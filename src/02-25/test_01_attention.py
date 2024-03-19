'''
Author: larry combofish@163.com
Date: 2024-02-28 19:04:12
LastEditors: larry combofish@163.com
LastEditTime: 2024-03-18 21:12:31
FilePath: /code-write/src/02-25/test_01_attention.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import torch
import torch.nn as nn
from icecream import ic


class Attention(nn.Module):
    def __init__(self, dim, n_heads, qkv_bias=False, qk_scale=None, attn_drop=0., proj_drop=0.):
        super().__init__()

        self.n_heads = n_heads
        self.qkv = nn.Linear(dim, dim*3, bias=qkv_bias)

        head_dim = dim // n_heads
        self.scale = qk_scale or head_dim ** -0.5
        self.attn_drop = nn.Dropout(attn_drop)
        self.proj = nn.Linear(dim, dim)
        self.proj_drop = nn.Dropout(proj_drop)

    def forward(self, inputs):
        B, N, L = inputs.size()
        qkv = self.qkv(inputs).reshape(B, N, 3, self.n_heads,
                                       L//self.n_heads).permute(2, 0, 3, 1, 4)
        q, k, v = qkv[0], qkv[1], qkv[2]

        attn = (q @ k.transpose(-2, -1)) * self.scale
        attn = attn.softmax(dim=-1)
        attn = self.attn_drop(attn)
        
        """
        q.shape:            torch.Size([4, 8, 65, 96])
        k.shape:            torch.Size([4, 8, 65, 96])
        v.shape:            torch.Size([4, 8, 65, 96])
        attn.shape:         torch.Size([4, 8, 65, 65])
        tmp = (attn @ v)
        tmp.shape:          torch.Size([4, 8, 65, 96])
        tmp.transpose(1, 2).shape:         torch.Size([4, 65, 8, 96])
        """

        x = (attn @ v).transpose(1, 2).reshape(B, N, L)
        x = self.proj(x)
        x = self.proj_drop(x)

        return x


if __name__ == '__main__':
    attn = Attention(768, 8).cuda()

    inputs = torch.randn((4, 65, 768)).cuda()
    output = attn(inputs)

    ic(inputs.size(), output.size())
