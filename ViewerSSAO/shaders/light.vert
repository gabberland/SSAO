#version 330 core
layout (location = 0) in vec3 vert;
layout (location = 1) in vec3 normal;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
uniform mat3 normal_matrix;

out vec3 N;
out vec3 V;

void main()
{

    vec4 view_vertex = view * model * vec4(vert, 1);
    V = view_vertex.xyz;
    N = normalize(normal_matrix * normal);

    gl_Position = projection * view_vertex;

}
