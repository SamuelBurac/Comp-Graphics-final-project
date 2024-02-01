#version 330 core

/*default camera matrices. do not modify.*/
layout (std140) uniform camera
{
	mat4 projection;	/*camera's projection matrix*/
	mat4 view;			/*camera's view matrix*/
	mat4 pvm;			/*camera's projection*view*model matrix*/
	mat4 ortho;			/*camera's ortho projection matrix*/
	vec4 position;		/*camera's position in world space*/
};

/* Passed time from the begining of the program */ 
uniform float iTime;

/*input variables*/
in vec4 vtx_color;
in vec4 worldPos; 
in vec3 fragNormal;
/*output variables*/
out vec4 frag_color;	/*or use gl_FragColor*/

void main()							
{	
	// frag_color = vec4(vtx_color.rgb, 1.0);
	// vec3 lightDir = normalize(vec3(300, 200, 200) - worldPos.xyz);
	vec3 lightDir1 = normalize(vec3(.1, .5, 1));
	vec3 lightDir2 = normalize(vec3(1, .4, -1));
	vec3 lightDir3 = normalize(vec3(-1, .6, -1));
	vec3 n = normalize(fragNormal);
	vec3 d = vtx_color.rgb * max(dot(n, lightDir1), 0.0) * 0.7;
	d += vtx_color.rgb * max(dot(n, lightDir2), 0.0) * 0.3;
	d += vtx_color.rgb * max(dot(n, lightDir3), 0.0) * 0.3;
	// vec3 a = vtx_color.rgb * 0.1;
	// vec3 s = vec3(0.2, 0.2, 0.2) * pow(max(dot(n, normalize(lightDir1 + normalize(position.xyz - worldPos.xyz))), 0.0), 32.0);
	frag_color = vec4(d, 1.0);
}	