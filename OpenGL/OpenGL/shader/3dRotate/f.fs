#version 330 core
in vec2 TexCoord;
uniform sampler2D ourTexture;

out vec4 color;
void main()
{
    color = texture(ourTexture, TexCoord);
}