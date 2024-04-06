# 3D Colour Space
Show colour spaces as a 3d object .obj file

![Viewport](data/viewport.png)
![Viewport GIF](data/viewport_gif.gif)
<!-- https://convertio.co -->

## Coordinates Representation

### In Blender
| Colour Space | X | Y | Z |
| --- | --- | --- | --- |
| sRGB | R | G | B |
| Linear RGB | R | G | B |
| CIE XYZ | X | Y | Z |
| Linear LMS | L | M | S |
| LMS | L | M | S |
| OkLab[^1] | a | b | L |

### In .obj file
| Colour Space | X | Y | Z |
| --- | --- | --- | --- |
| sRGB | R | B | G |
| Linear RGB | R | B | G |
| CIE XYZ | X | Z | Y |
| Linear LMS | L | S | M |
| LMS | L | S | M |
| OkLab | L | b | a |

[^1]: OkLab 3D Object was rotated to align with other objects *(y: -90°, z: -90°)**