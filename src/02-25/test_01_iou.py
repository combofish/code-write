'''
Author: larry combofish@163.com
Date: 2024-02-28 16:02:16
LastEditors: larry combofish@163.com
LastEditTime: 2024-02-28 16:19:23
FilePath: /code-write/src/02-25/test_01_iou.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
from icecream import ic


def iou(bbox1, bbox2):
    x1, y1, x2, y2 = bbox1
    x3, y3, x4, y4 = bbox2

    area1 = (x2 - x1) * (y2 - y1)
    area2 = (y4 - y3) * (x4 - x3)

    xmin = max(x1, x3)
    ymin = max(y1, y3)
    xmax = min(x2, x4)
    ymax = min(y2, y4)

    w = max(0, ymax - ymin)
    h = max(0, xmax - xmin)

    inter = h * w
    union = area1 + area2 - inter
    iou = inter / union

    return iou


def iou2(bbox1, bbox2):
    x1, y1, x2, y2 = bbox1
    x3, y3, x4, y4 = bbox2

    area1 = (x2 - x1 + 1) * (y2 - y1 + 1)
    area2 = (y4 - y3 + 1) * (x4 - x3 + 1)

    xmin = max(x1, x3)
    ymin = max(y1, y3)
    xmax = min(x2, x4)
    ymax = min(y2, y4)

    w = max(0, ymax - ymin + 1)
    h = max(0, xmax - xmin + 1)

    inter = h * w
    union = area1 + area2 - inter
    iou = inter / union

    return iou


if __name__ == '__main__':
    bbox1 = [1, 1, 3, 3]
    bbox2 = [2, 2, 4, 4]

    ic(iou(bbox1, bbox2))
    ic(iou2(bbox1, bbox2))
