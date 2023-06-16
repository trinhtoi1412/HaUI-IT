//Chuong trình v? 1 hình l?p phuong don v? theo mô hình l?p trình OpenGL hi?n d?i

#include "Angel.h"  /* Angel.h là file t? phát tri?n (tác gi? Prof. Angel), có ch?a c? khai báo includes glew và freeglut*/


// remember to prototype
void generateGeometry(void);
void initGPUBuffers(void);
void shaderSetup(void);
void display(void);
void keyboard(unsigned char key, int x, int y);


typedef vec4 point4;
typedef vec4 color4;
using namespace std;

// S? các d?nh c?a các tam giác
const int NumPoints = 36;

point4 points[NumPoints]; /* Danh sách các d?nh c?a các tam giác c?n v?*/
color4 colors[NumPoints]; /* Danh sách các màu tuong ?ng cho các d?nh trên*/
vec3 normals[NumPoints]; /*Danh sách các vector pháp tuy?n ?ng v?i m?i d?nh*/

point4 vertices[8]; /* Danh sách 8 d?nh c?a hình l?p phuong*/
color4 vertex_colors[8]; /*Danh sách các màu tuong ?ng cho 8 d?nh hình l?p phuong*/

GLuint program, model_loc, view_loc, projection_loc;
mat4 model, view, projection;
mat4 instance, instance_room;
mat4 ctm_phong;
GLfloat mauAnhSang = 1.0;
GLfloat opacity = 1.0;
float Opacity = 1.0;
GLfloat choisang = 0.2;
GLfloat mauBD = 255;

GLdouble x_phong, y_phong, z_phong;

GLfloat thetax = 0, thetay = 0, thetam = 0, thetamd = 0, thetamt = 0, thetaq = 0, thetat = 0;
void initCube()
{
	// Gán giá tr? t?a d? v? trí cho các d?nh c?a hình l?p phuong
	vertices[0] = point4(-0.5, -0.5, 0.5, 1.0);
	vertices[1] = point4(-0.5, 0.5, 0.5, 1.0);
	vertices[2] = point4(0.5, 0.5, 0.5, 1.0);
	vertices[3] = point4(0.5, -0.5, 0.5, 1.0);
	vertices[4] = point4(-0.5, -0.5, -0.5, 1.0);
	vertices[5] = point4(-0.5, 0.5, -0.5, 1.0);
	vertices[6] = point4(0.5, 0.5, -0.5, 1.0);
	vertices[7] = point4(0.5, -0.5, -0.5, 1.0);

	// Gán giá tr? màu s?c cho các d?nh c?a hình l?p phuong	
	vertex_colors[0] = color4(0.0, 0.0, 0.0, 1.0); // black
	vertex_colors[1] = color4(1.0, 0.0, 0.0, 1.0); // red
	vertex_colors[2] = color4(1.0, 1.0, 0.0, 1.0); // yellow
	vertex_colors[3] = color4(0.0, 1.0, 0.0, 1.0); // green
	vertex_colors[4] = color4(0.0, 0.0, 1.0, 1.0); // blue
	vertex_colors[5] = color4(1.0, 0.0, 1.0, 1.0); // magenta
	vertex_colors[6] = color4(1.0, 1.0, 1.0, 1.0); // white
	vertex_colors[7] = color4(0.0, 1.0, 1.0, 1.0); // cyan
}
int Index = 0;
void quad(int a, int b, int c, int d)  /*T?o m?t m?t hình l?p phuong = 2 tam giác, gán màu cho m?i d?nh tuong ?ng trong m?ng colors*/
{
	vec4 u = vertices[b] - vertices[a];
	vec4 v = vertices[c] - vertices[b];
	vec3 normal = normalize(cross(u, v));

	normals[Index] = normal; colors[Index] = vertex_colors[a]; points[Index] = vertices[a]; Index++;
	normals[Index] = normal; colors[Index] = vertex_colors[a]; points[Index] = vertices[b]; Index++;
	normals[Index] = normal; colors[Index] = vertex_colors[a]; points[Index] = vertices[c]; Index++;
	normals[Index] = normal; colors[Index] = vertex_colors[a]; points[Index] = vertices[a]; Index++;
	normals[Index] = normal; colors[Index] = vertex_colors[a]; points[Index] = vertices[c]; Index++;
	normals[Index] = normal; colors[Index] = vertex_colors[a]; points[Index] = vertices[d]; Index++;
}
void makeColorCube(void)  /* Sinh ra 12 tam giác: 36 d?nh, 36 màu*/

{
	quad(1, 0, 3, 2);
	quad(2, 3, 7, 6);
	quad(3, 0, 4, 7);
	quad(6, 5, 1, 2);
	quad(4, 5, 6, 7);
	quad(5, 4, 0, 1);
}
void generateGeometry(void)
{
	initCube();
	makeColorCube();
}


void initGPUBuffers(void)
{
	// T?o m?t VAO - vertex array object
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// T?o và kh?i t?o m?t buffer object
	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors) + sizeof(normals), NULL, GL_STATIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(points), points);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(points), sizeof(colors), colors);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors), sizeof(normals), normals);
}


void shaderSetup(void)
{
	// N?p các shader và s? d?ng chuong trình shader
	program = InitShader("vshader1.glsl", "fshader1.glsl");   // hàm InitShader khai báo trong Angel.h
	glUseProgram(program);

	// Kh?i t?o thu?c tính v? trí d?nh t? vertex shader
	GLuint loc_vPosition = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(loc_vPosition);
	glVertexAttribPointer(loc_vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	GLuint loc_vColor = glGetAttribLocation(program, "vColor");
	glEnableVertexAttribArray(loc_vColor);
	glVertexAttribPointer(loc_vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(points)));

	GLuint loc_vNormal = glGetAttribLocation(program, "vNormal");
	glEnableVertexAttribArray(loc_vNormal);
	glVertexAttribPointer(loc_vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(points) + sizeof(colors)));

	model_loc = glGetUniformLocation(program, "Model");
	view_loc = glGetUniformLocation(program, "View");
	projection_loc = glGetUniformLocation(program, "Projection");
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0, 1.0, 1.0, 1.0);        /* Thi?t l?p màu tr?ng là màu xóa màn hình*/
}
void changeColor(GLfloat a, GLfloat b, GLfloat c) {
	/* Kh?i t?o các tham s? chi?u sáng - tô bóng*/
	point4 light_position(0.0, 2.0, 0.0, 1.0);
	color4 light_ambient(0.2, 0.2, 0.2, 1.0);
	color4 light_diffuse(mauAnhSang, mauAnhSang, mauAnhSang, 1.0);
	color4 light_specular(choisang, choisang, choisang, 1.0);

	color4 material_ambient(1.0, 0.0, 1.0, 1.0);
	color4 material_diffuse(a / 255.0, b / 255.0, c / 255.0, 1.0);
	color4 material_specular(255.0 / 255.0, 255.0 / 255.0, 255 / 255.0, 1.0);
	float material_shininess = 100.0;

	color4 ambient_product = light_ambient * material_ambient;
	color4 diffuse_product = light_diffuse * material_diffuse;
	color4 specular_product = light_specular * material_specular;

	glUniform4fv(glGetUniformLocation(program, "AmbientProduct"), 1, ambient_product);
	glUniform4fv(glGetUniformLocation(program, "DiffuseProduct"), 1, diffuse_product);
	glUniform4fv(glGetUniformLocation(program, "SpecularProduct"), 1, specular_product);
	glUniform4fv(glGetUniformLocation(program, "LightPosition"), 1, light_position);
	glUniform1f(glGetUniformLocation(program, "Shininess"), material_shininess);
	//glUniform1f(glGetUniformLocation(program, "Opacity"), Opacity);
}
void wall_room(GLfloat w, GLfloat l, GLfloat h) {
	instance = Scale(w, h, l);
	glUniformMatrix4fv(model_loc, 1, GL_TRUE, ctm_phong * model * instance_room * instance);
	glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}
void wall_build() {
	//d?ng n?n can phòng
	instance_room = Translate(0.0, 0.0, 0.0);
	changeColor(124, 252, 0);
	wall_room(14, 14, 1);

	//tran nha
	instance_room = Translate(0.0, 4.5, 0.0);
	changeColor(124, 252, 0);
	wall_room(12, 12, 0.1);

	//tu?ng ph?i
	instance_room = Translate(6.1, 2.5, 0.0);
	changeColor(0, 255, 255);
	wall_room(0.2, 12, 4);

	//tu?ng trái
	instance_room = Translate(-6.1, 2.5, 0.0);
	changeColor(0, 255, 255);
	wall_room(0.2, 12, 4);

	//tu?ng sau
	instance_room = Translate(0.0, 2.5, -6.1);
	changeColor(0, 255, 255);
	wall_room(12, 0.2, 4);

	//tuong cua
	instance_room = Translate(4.5, 2.5, 6.1);
	changeColor(0, 255, 255);
	wall_room(3, 0.2, 4);
	instance_room = Translate(-4.5, 2.5, 6.1);
	changeColor(0, 255, 255);
	wall_room(3, 0.2, 4);

	//cua cuon
	instance_room = Translate(0, 2.5 + thetat, 6.1);
	changeColor(255, 255, 255);
	wall_room(6, 0.2, 4 - 2 * thetat);
}
mat4 instance_ban, instance_ke;
void matban(GLfloat w, GLfloat l, GLfloat h)
{
	instance = Scale(w, h, l);
	glUniformMatrix4fv(model_loc, 1, GL_TRUE, ctm_phong * model * instance_room * instance_ban * instance);
	glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}
//=============== VẼ ĐÈN=======================
mat4 instance_den;
bool bat_den = true;
void den(GLfloat w, GLfloat h, GLfloat t) {
	instance = Scale(w, h, t);
	glUniformMatrix4fv(model_loc, 1, GL_TRUE, ctm_phong * model * instance_room * instance_den * instance);
	glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void den_build() {
	// tren
	changeColor(255, 215, 0);
	instance_den = Translate(0, 0.03, 0);
	den(0.64, 0.04, 0.15);
	//truoc 
	instance_den = Translate(0, 0, -0.075);
	den(0.6, 0.06, 0.02);
	//sau 
	// vi l < -> TT
	instance_den = Translate(0, 0, 0.075);
	den(0.6, 0.06, 0.02);
	//trai
	instance_den = Translate(-0.3, 0, 0);
	den(0.04, 0.06, 0.15);
	//phai
	instance_den = Translate(0.3, 0, 0);
	den(0.04, 0.06, 0.15);
	// bong den
	changeColor(mauBD, mauBD, mauBD);
	instance_den = Translate(0, -0.03, 0);
	den(0.5, 0.06, 0.1);
}

void ban_build() {
	//m?t bàn o giua
	instance_ban = Translate(0.0, 0.0, 0.0);
	changeColor(0, 255, 255);
	matban(4, 6, 1);
	instance_ban = Translate(0.0, 0.25, 0.0);
	changeColor(175, 215, 136);
	matban(2, 4, 1.5);

}

void matke(GLfloat w, GLfloat l, GLfloat h)
{
	instance = Scale(w, h, l);
	glUniformMatrix4fv(model_loc, 1, GL_TRUE, ctm_phong * model * instance_room * instance_ke * instance);
	glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}
void chanke(GLfloat w, GLfloat l, GLfloat h)
{
	instance = Scale(w, h, l);
	glUniformMatrix4fv(model_loc, 1, GL_TRUE, ctm_phong * model * instance_room * instance_ke * instance);
	glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}


void ketrai() {
	instance_ke = Translate(0, 0, 0);
	changeColor(255, 130, 71);
	matke(1, 4, 0.05);
	instance_ke = Translate(0, 1, 0);
	changeColor(255, 130, 71);
	matke(1, 4, 0.05);
}
void kephai() {
	instance_ke = Translate(0.0, 0.0, 0.0);
	changeColor(255, 130, 71);
	matke(1, 8, 0.05);

	instance_ke = Translate(0, 0, -3.5);
	changeColor(255, 255, 0);
	chanke(0.05, 0.05, 4);
	instance_ke = Translate(0, 0, 0);
	changeColor(255, 255, 0);
	chanke(0.05, 0.05, 4);
	instance_ke = Translate(0, 0, 3.5);
	changeColor(255, 255, 0);
	chanke(0.05, 0.05, 4);

	instance_ke = Translate(0, 1, 0);
	changeColor(255, 130, 71);
	matke(1, 8, 0.05);

	instance_ke = Translate(0, 2, 0);
	changeColor(255, 130, 71);
	matke(1, 8, 0.05);

	//cua keo
	instance_ke = Translate(-0.5, 0.5, 2 + thetamd);
	changeColor(255, 255, 0);
	matke(0.05, 4, 1);
	instance_ke = Translate(-0.5, 1.5, -2 + thetamt);
	changeColor(255, 255, 0);
	matke(0.05, 4, 1);

}
mat4 instance_tu;
void mattu(GLfloat w, GLfloat l, GLfloat h)
{
	instance = Scale(w, h, l);
	glUniformMatrix4fv(model_loc, 1, GL_TRUE, ctm_phong * model * instance_room * instance_tu * instance);
	glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}
void tu() {
	instance_tu = Translate(0.0, 0.0, 0.0);
	changeColor(255, 255, 0);
	mattu(1.5, 2, 0.06);
	instance_tu = Translate(0.0, 1.5, 0.0);
	changeColor(255, 255, 0);
	mattu(1.5, 2, 0.06);
	instance_tu = Translate(0.0, 3.0, 0.0);
	changeColor(255, 255, 0);
	mattu(1.5, 2, 0.06);
	instance_tu = Translate(0.0, 1.47, -0.97);
	changeColor(255, 255, 0);
	mattu(1.5, 0.06, 3);
	instance_tu = Translate(0.0, 1.47, 0.97);
	changeColor(255, 255, 0);
	mattu(1.5, 0.06, 3);

	//canh tu
	instance_tu = Translate(0.75, 1.53, -thetam);
	changeColor(255, 255, 0);
	mattu(0.05, 2, 3);

}
void tu_thungan() {
	instance_tu = Translate(0.0, 0.0, 0.0);
	changeColor(223, 188, 148);
	mattu(1, 2, 0.06);
	instance_tu = Translate(0.0, 0.75, 0.0);
	changeColor(223, 188, 148);
	mattu(1, 2, 0.06);
	instance_tu = Translate(0.0, 1.5, 0.0);
	changeColor(223, 188, 148);
	mattu(1, 2, 0.06);
	instance_tu = Translate(0.0, 2.25, 0.0);
	changeColor(223, 188, 148);
	mattu(1, 2, 0.06);
	instance_tu = Translate(0.0, 3.00, 0.0);
	changeColor(223, 188, 148);
	mattu(1, 2, 0.06);
	instance_tu = Translate(0.0, 3.5, 0.0);
	changeColor(175, 215, 136);
	mattu(1, 2, 0.06);

	instance_tu = Translate(0.0, 1.8, -0.97);
	changeColor(175, 215, 136);
	mattu(1, 0.06, 3.5);
	instance_tu = Translate(0.0, 1.8, 0.97);
	changeColor(175, 215, 136);
	mattu(1, 0.06, 3.5);


	instance_tu = Translate(-3.2, 3.5, 0.0);
	changeColor(175, 215, 136);
	mattu(1, 2, 0.06);
	instance_tu = Translate(-3.2, 1.8, -0.97);
	changeColor(175, 215, 136);
	mattu(1, 0.06, 3.5);
	instance_tu = Translate(-3.2, 1.8, 0.97);
	changeColor(175, 215, 136);
	mattu(1, 0.06, 3.5);
}
mat4 instance_thungan;
void thungan(GLfloat w, GLfloat l, GLfloat h)
{
	instance = Scale(w, h, l);
	glUniformMatrix4fv(model_loc, 1, GL_TRUE, ctm_phong * model * instance_room * instance_thungan * instance);
	glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}
void quay_thungan() {
	instance_thungan = Translate(0.0, 0.0, 0.0);
	changeColor(175, 215, 136);
	thungan(3, 0.5, 1);
	instance_thungan = Translate(2.0, 1.25, 0.0);
	changeColor(175, 215, 136);
	thungan(1, 0.5, 3.5);
	instance_thungan = Translate(-1.2, 1.25, 0.0);
	changeColor(175, 215, 136);
	thungan(1, 0.5, 3.5);

}
mat4 instance_logo;
void logo(GLfloat w, GLfloat l, GLfloat h)
{
	instance = Scale(w, h, l);
	glUniformMatrix4fv(model_loc, 1, GL_TRUE, ctm_phong * model * instance_room * instance_logo * instance);
	glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}
void t() {
	//chu T
	instance_logo = Translate(0.0, 0.0, 0.0);
	changeColor(224, 110, 60);
	logo(0.35, 0.05, 1);
	instance_logo = Translate(0.0, 0.35, 0.0);
	changeColor(224, 110, 60);
	logo(1, 0.05, 0.3);

	//chu O

}
void o() {
	instance_logo = Translate(0, -0.35, 0.0);
	changeColor(255, 255, 0);
	logo(1, 0.05, 0.3);
	instance_logo = Translate(0, 0.35, 0.0);
	changeColor(255, 255, 0);
	logo(1, 0.05, 0.3);

	instance_logo = Translate(-0.35, 0, 0.0);
	changeColor(255, 255, 0);
	logo(0.3, 0.05, 1);
	instance_logo = Translate(0.35, 0, 0.0);
	changeColor(255, 255, 0);
	logo(0.3, 0.05, 1);
}
void y() {
	instance_logo = Translate(0, -0.3, 0.0);
	changeColor(124, 252, 0);
	logo(1, 0.05, 0.3);

	instance_logo = Translate(-0.35, 0, 0.0);
	changeColor(124, 252, 0);
	logo(0.3, 0.05, 0.55);
	instance_logo = Translate(0.35, 0, 0.0);
	changeColor(124, 252, 0);
	logo(0.3, 0.05, 0.55);

	instance_logo = Translate(0.0, -0.5, 0.0);
	changeColor(124, 252, 0);
	logo(0.3, 0.05, 0.7);
}
void toy() {
	t();
	instance_logo = Translate(1, 0, 0);
	o();
}
mat4 instance_mb;
void maybay(GLfloat w, GLfloat l, GLfloat h)
{
	instance = Scale(w, h, l);
	glUniformMatrix4fv(model_loc, 1, GL_TRUE, ctm_phong * model * instance_room * instance_mb * instance);
	glDrawArrays(GL_TRIANGLES, 0, NumPoints);
}

void maybayto() {
	//than
	instance_mb = Translate(0.0, 0, 0.0);
	changeColor(210, 150, 50);
	maybay(1, 1, 1);
	instance_mb = Translate(0.0, 0.0, 0.5);
	changeColor(255, 255, 0);
	maybay(0.8, 0.5, 0.75);

	instance_mb = Translate(0.0, 0.5, 0.0);
	changeColor(12, 255, 0);
	maybay(0.3, 0.3, 0.3);
	instance_mb = Translate(0.0, 0.7, 0.0);
	changeColor(212, 55, 0);
	maybay(0.1, 0.1, 0.5);

	instance_mb = Translate(0.0, 0, -1.5);
	changeColor(124, 100, 0);
	maybay(0.2, 2, 0.2);
	instance_mb = Translate(0.0, 0, -2.5);
	changeColor(124, 100, 0);
	maybay(0.5, 0.5, 0.5);

	//chan
	instance_mb = Translate(-0.3, -0.6, 0);
	changeColor(255, 255, 255);
	maybay(0.1, 0.6, 0.3);
	instance_mb = Translate(0.3, -0.6, 0);
	changeColor(255, 255, 255);
	maybay(0.1, 0.6, 0.3);
	//cang
	instance_mb = Translate(-0.3, -0.8, 0);
	changeColor(170, 50, 50);
	maybay(0.3, 1.5, 0.1);
	instance_mb = Translate(0.3, -0.8, 0);
	changeColor(170, 50, 50);
	maybay(0.3, 1.5, 0.1);
	//canh quat
	instance_mb = RotateY(thetaq);
	instance_mb = instance_mb * Translate(0.0, 0.8, 0.0);
	changeColor(255, 130, 71);
	maybay(3, 0.2, 0.05);
	instance_mb = instance_mb * Translate(0.0, 0.0, 0.0);
	changeColor(255, 255, 0);
	maybay(0.2, 3, 0.05);
}
void maybaynho(GLint x, GLint y, GLint z) {
	instance_mb = Translate(0.0, 0, 0.0);
	changeColor(150, 200, 150);
	maybay(0.1, 0.8, 0.1);

	//lung
	instance_mb = Translate(0.0, 0.05, 0.15);
	changeColor(x, y, z);
	maybay(0.06, 0.3, 0.06);
	//dau
	instance_mb = Translate(0.0, 0.0, 0.4);
	changeColor(x, y, z);
	maybay(0.06, 0.06, 0.06);

	//duoi
	instance_mb = Translate(0.0, 0.05, -0.4);
	changeColor(x, y, z);
	maybay(0.02, 0.1, 0.1);

	//canh
	instance_mb = Translate(0.15, 0, 0.1) * RotateY(35);
	changeColor(x, y, z);
	maybay(0.4, 0.06, 0.01);
	instance_mb = Translate(-0.15, 0, 0.1) * RotateY(-35);
	changeColor(x, y, z);
	maybay(0.4, 0.06, 0.01);
}
void room_build() {
	model = RotateY(thetay) * RotateX(thetax);
	wall_build();

	instance_room = Translate(4, 4.4, -3);
	den_build();
	instance_room = Translate(4, 4.4, 0);
	den_build();
	instance_room = Translate(4, 4.4, 3);
	den_build();

	instance_room = Translate(0, 4.4, -3);
	den_build();
	instance_room = Translate(0, 4.4, 0);
	den_build();
	instance_room = Translate(0, 4.4, 3);
	den_build();

	instance_room = Translate(-4, 4.4, -3);
	den_build();
	instance_room = Translate(-4, 4.4, 0);
	den_build();
	instance_room = Translate(-4, 4.4, 3);
	den_build();

	instance_room = Translate(0, 0.5, 0);
	ban_build();
	instance_room = Translate(-5.5, 1.5, -4);
	ketrai();

	instance_room = Translate(-5.25, 0.5, -1);
	tu();
	instance_room = Translate(-5.5, 1.5, 2);
	ketrai();
	instance_room = Translate(5.5, 1.5, 0);
	kephai();
	instance_room = Translate(5.5, 0.5, -5);
	tu_thungan();
	instance_room = Translate(3.5, 1, -4.25);
	quay_thungan();
	instance_room = Translate(-3, 2.5, -6);
	t();
	instance_room = Translate(-1.9, 2.5, -6);
	o();
	instance_room = Translate(-0.8, 2.7, -6);
	y();
	instance_room = Translate(0, 2.5, 0);
	maybayto();
	instance_room = Translate(-5.2, 2, 0.8) * RotateZ(-45);
	maybaynho(50, 25, 130);
	instance_room = Translate(-5.2, 2, 1.8) * RotateZ(-45);
	maybaynho(150, 25, 13);
	instance_room = Translate(-5.2, 2, 2.8) * RotateZ(-45);
	maybaynho(90, 143, 38);
	instance_room = Translate(-5.2, 2, -2.8) * RotateZ(-45);
	maybaynho(50, 25, 130);
	instance_room = Translate(-5.2, 2, -3.8) * RotateZ(-45);
	maybaynho(150, 25, 13);
	instance_room = Translate(-5.2, 2, -4.8) * RotateZ(-45);
	maybaynho(90, 143, 38);

	instance_room = Translate(5.2, 2, 0.8) * RotateZ(45);
	maybaynho(50, 25, 130);
	instance_room = Translate(5.2, 2, 1.8) * RotateZ(45);
	maybaynho(150, 25, 13);
	instance_room = Translate(5.2, 2, 2.8) * RotateZ(45);
	maybaynho(90, 143, 38);
	instance_room = Translate(5.2, 2, -0.8) * RotateZ(45);
	maybaynho(50, 25, 130);
	instance_room = Translate(5.2, 2, -1.8) * RotateZ(45);
	maybaynho(150, 25, 13);
	instance_room = Translate(5.2, 2, -2.8) * RotateZ(45);
	maybaynho(90, 143, 38);

	instance_room = Translate(5.2, 3, 0.8) * RotateZ(45);
	maybaynho(50, 25, 130);
	instance_room = Translate(5.2, 3, 1.8) * RotateZ(45);
	maybaynho(150, 25, 13);
	instance_room = Translate(5.2, 3, 2.8) * RotateZ(45);
	maybaynho(90, 143, 38);
	instance_room = Translate(5.2, 3, -0.8) * RotateZ(45);
	maybaynho(50, 25, 130);
	instance_room = Translate(5.2, 3, -1.8) * RotateZ(45);
	maybaynho(150, 25, 13);
	instance_room = Translate(5.2, 3, -2.8) * RotateZ(45);
	maybaynho(90, 143, 38);
}

GLfloat l = -2.5, r = 2.5;
GLfloat bottom = -2.5, top = 2.5;
GLfloat zNear = 1, zFar = 17;
GLfloat z_eye = 9, y_eye = 2;
GLdouble xx_p, yy_ph, zz_p;

bool view_phong = true;
bool view_mbto = true;

void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	const vec3 viewer_pos(0.0, y_eye, z_eye);  /*Trùng v?i eye c?a camera*/

	ctm_phong = Translate(x_phong, y_phong, z_phong) * RotateY(yy_ph);
	room_build();
	vec4 eye(0.0, y_eye, z_eye, 1);
	vec4 at(0, 0, 0, 1);
	vec4 up(0, 1, 0, 1);
	view = LookAt(eye, at, up);
	glUniformMatrix4fv(view_loc, 1, GL_TRUE, view);

	projection = Frustum(l, r, bottom, top, zNear, zFar);
	glUniformMatrix4fv(projection_loc, 1, GL_TRUE, projection);
	glutSwapBuffers();
}
void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
}
void canhquatquay() {
	thetaq += 45;
	if (thetaq > 360) {
		thetaq -= 360;
	}
	glutPostRedisplay();
}
void stop(void) {

}
void mocuacuon() {
	if (thetat < 2)
		thetat += 0.001;
	glutPostRedisplay();
}
void dongcuacuon() {
	if (thetat >= 0)
		thetat -= 0.001;
	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
	// keyboard handler

	switch (key) {
	case 033:			// 033 is Escape key octal value
		exit(1);		// quit program
		break;
	case 'w':
		thetax += 5;
		glutPostRedisplay();
		break;
	case 's':
		thetax -= 5;
		glutPostRedisplay();
		break;
	case 'a':
		thetay += 5;
		glutPostRedisplay();
		break;
	case 'd':
		thetay -= 5;
		glutPostRedisplay();
		break;
	// mo tu ke trai
	case 'e':
		if (thetam <= 2)
			thetam += 0.1;
		else thetam = 0;
		glutPostRedisplay();
		break;
	// mo ke phai phia duoi
	case 'f':
		if (thetamd >= -4)
			thetamd -= 0.1;
		else thetamd = 0;
		glutPostRedisplay();
		break;
	// mo ke phai phia tren
	case 'r':
		if (thetamt <= 4)
			thetamt += 0.1;
		else thetamt = 0;
		glutPostRedisplay();
		break;
	// quay canh quat may bay to
	case 'q':
		glutIdleFunc(canhquatquay);
		break;
	case 'Q':
		glutIdleFunc(stop);
		break;
	// mo cua cuon
	case 't':
		glutIdleFunc(mocuacuon);
		break;
	// dong cua cuon
	case 'T':
		glutIdleFunc(dongcuacuon);
		break;
	// bat den
	case '1':
		if (bat_den) {
			mauBD = 100;
			mauAnhSang = 0.2;
			bat_den = false;
		}
		else {
			mauBD = 255;
			mauAnhSang = 1;
			bat_den = true;
		}
		glutPostRedisplay();
		break;
	// di chuyen camera den vi tri ngoai cua hang
	case '2':
		if (view_mbto) {
			z_eye = 9;
			zNear = 1;
		}
		glutPostRedisplay();
		break;
	// di chuyen camera den vi tri trong cua hang
	case '3':
		if (view_phong) {
			z_eye = 5;
			zNear = 2;
		}
		glutPostRedisplay();
		break;
	// di chuyen camera den vi tri may bay to
	case '4':
		if (view_mbto) {
			z_eye = 3;
			zNear = 1;
		}
		glutPostRedisplay();
		break;
	}
	
}


int main(int argc, char** argv)
{
	// main function: program starts here

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1000, 720);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Drawing a AirPlane Toy Store");


	glewInit();

	generateGeometry();
	initGPUBuffers();
	shaderSetup();

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}