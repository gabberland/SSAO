#version 330 core
layout (location = 0) in vec3 vert;

out vec2 TexCoords;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main(void)
{
    vec4 view_vertex = view * model * vec4(vert, 1);

    vec2 FragPos = vec2(vert.x,vert.y);

    TexCoords = (FragPos * vec2(0.5)) + vec2(0.5);

    gl_Position = projection * view_vertex;
}
