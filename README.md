# 3D Colour Space
Show colour spaces as a 3d object .obj file

![Viewport](data/viewport.png)
![Viewport GIF](data/viewport_gif.gif)
<!-- https://convertio.co -->

## Coordinates Representation [^1]

| Colour Space | X | Y | Z |
| --- | --- | --- | --- |
| sRGB | R | G | B |
| Linear RGB | R | G | B |
| CIE XYZ | X | Y | Z |
| Linear LMS | L | M | S |
| LMS | L | M | S |
| OkLab [^2] | a | b | L |

## Minimum & Maximum Values [^3]

| CIE XYZ | Min | Max |
|---|---|---|
| X | 0.000000 | 0.950470 |
| Y | 0.000000 | 1.000000 |
| Z | 0.000000 | 1.088830 |

| Linear LMS | Min | Max |
|---|---|---|
| L | 0.000000 | 0.999932 |
| M | 0.000000 | 1.000019 |
| S | 0.000000 | 1.000336 |

| LMS | Min | Max |
|---|---|---|
| L | 0.000000 | 0.999977 |
| M | 0.000000 | 1.000006 |
| S | 0.000000 | 1.000112 |

| OkLab | Min | Max |
|---|---|---|
| L     |  0.000000 | 1.000000 |
| a[^4] | -0.233916 | 0.276221 |
| b[^4] | -0.311611 | 0.198484 |

### OkLab Colours at Minimums & Maximums

| Value | Min | Max |
|---|---|---|
| L | ![#000000](https://placehold.co/15x15/000000/000000.png) `#000000` | ![#FFFFFF](https://placehold.co/15x15/FFFFFF/FFFFFF.png) `#FFFFFF` |
| a | ![#00FF00](https://placehold.co/15x15/00FF00/00FF00.png) `#00FF00` | ![#FF00DF](https://placehold.co/15x15/FF00DF/FF00DF.png) `#FF00DF` |
| b | ![#0000FF](https://placehold.co/15x15/0000FF/0000FF.png) `#0000FF` | ![#FFFF00](https://placehold.co/15x15/FFFF00/FFFF00.png) `#FFFF00` |

[^1]: Blender Import/Export Settings: +Y Forward & +Z Up
[^2]: Coordinates changed so L value is up
[^3]: Some calculations may be due to floating point errors - code uses double
[^4]: Generally, a value between [-0.4 and 0.4](https://bit.ly/3VJBNl6) is accepted