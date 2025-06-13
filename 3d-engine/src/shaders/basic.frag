#version 330 core

layout (location = 0) out vec4 fragColor;

in vec4 pos;
uniform vec2 light_pos = vec2(0.0, 0.0);
uniform float light_str = 0.5;

void main() {
	float L = length(pos.xy - light_pos);
	float intensity = light_str / sqrt(L);
	fragColor = vec4(0.871, 0.235, 0.298, 1.0) * intensity;
}