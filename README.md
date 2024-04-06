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
| OkLab | L | a | b |

### In .obj file
| Colour Space | X | Y | Z |
| --- | --- | --- | --- |
| sRGB | R | B | G |
| Linear RGB | R | B | G |
| CIE XYZ | X | Z | Y |
| Linear LMS | L | S | M |
| LMS | L | S | M |
| OkLab | L | b | a |