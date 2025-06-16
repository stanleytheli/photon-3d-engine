#version 330 core

layout (location = 0) out vec4 color;
in DATA {
	vec4 position;
	vec4 color;
} fs_in;


uniform vec2 light_pos = vec2(0.0, 0.0);

uniform vec4 lightColor = vec4(1.0, 1.0, 1.0, 1.0);
uniform float light_str = 0.1;

void main() {
	color = fs_in.color;

	float L = length(fs_in.position.xy - light_pos);
	float intensity = 1 / sqrt(L);
	color += light_str * lightColor * intensity;
}