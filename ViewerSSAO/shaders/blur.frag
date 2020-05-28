#version 330 core

out vec4 frag_color;

in vec2 TexCoords;

uniform sampler2D ssaoInput;

uniform float blurRadius;

uniform bool blur_flag;

const int texSize = 4;

void main()
{
    if (blur_flag){

        vec2 texelSize = 1.0 / vec2(textureSize(ssaoInput, 0));

        float nColor = 0.0;

        for (int x = -texSize; x < texSize; ++x)
        {
            for (int y = -texSize; y < texSize; ++y)
            {
                vec2 offset = vec2(float(x) * blurRadius, float(y) * blurRadius) * texelSize;
                nColor += texture(ssaoInput, TexCoords + offset).r;
            }
        }

        float weight = 2*texSize*2*texSize;

        frag_color = vec4(nColor/weight,nColor/weight,nColor/weight, 1.0);
    }

    else
    {
        vec4 color = texture(ssaoInput,TexCoords);
        frag_color = color;
    }
}
