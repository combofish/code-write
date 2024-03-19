'''
Author: larry combofish@163.com
Date: 2024-02-28 16:02:16
LastEditors: larry combofish@163.com
LastEditTime: 2024-02-28 16:42:04
FilePath: /code-write/src/02-25/test_01_iou.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import numpy as np
from icecream import ic


def nms(dets, thresh):
    x1 = dets[:, 0]
    y1 = dets[:, 1]
    x2 = dets[:, 2]
    y2 = dets[:, 3]
    scores = dets[:, 4]

    ic(x1, y1, x2, y2, scores)

    areas = (y2 - y1) * (x2 - x1)
    order = scores.argsort()[::-1]

    ic(areas, order)

    keep = []
    while (len(order) > 0):
        i = order[0]
        keep.append(i)

        xmin = np.maximum(x1[i], x1[order[1:]])
        ymin = np.maximum(y1[i], y1[order[1:]])
        xmax = np.minimum(x2[i], x2[order[1:]])
        ymax = np.minimum(y2[i], y2[order[1:]])

        h = np.maximum(0, ymax - ymin)
        w = np.maximum(0, xmax - xmin)
        inter = h * w
        union = inter / (areas[i] + areas[order[1:]] - inter)

        inds = np.where(union < thresh)[0]
        order = order[inds + 1]

    return keep


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

    dets = np.array([[30, 20, 230, 200, 1],
                     [210, 30, 420, 5, 0.8],
                     [50, 50, 260, 220, 0.9],
                     [430, 280, 460, 360, 0.7]])
    thresh = 0.35
    keep_dets = nms(dets, thresh)
    ic(keep_dets, dets[keep_dets])

    # print(keep_dets)
    # print(dets[keep_dets])
