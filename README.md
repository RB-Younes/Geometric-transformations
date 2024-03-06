# TP Geometric-transformations

This repository contains implementations of geometric transformation functions as part of the TP Geometric-transformations. The functions include image transposition, nearest neighbor interpolation, and image expansion using interpolation.

## Image Transposition (`transpose`)

The `transpose` function performs a planar symmetry of the input image according to the first diagonal (upper left to lower right corner).

## Nearest Neighbor Interpolation (`interpolate_nearest`)

The `interpolate_nearest` function computes the value of nearest neighbor interpolation in an image at a given position `(x, y)`.

## Image Expansion (`expand`)

The `expand` function multiplies the resolution of an image by a given factor using the specified interpolation method. If the input size is `(h, w)`, the output size will be `((h-1)*factor, (w-1)*factor)`.

---

These functions are designed for educational purposes and may require further optimization or customization for specific applications.
