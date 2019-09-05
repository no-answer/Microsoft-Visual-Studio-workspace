// OpenGLTest.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include <windows.h>
#include <gl/glut.h>
#include <math.h>

#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "opengl32.lib")


/**//*----------------------------------------------------------------------------
	*    ��ʼ������
	*/
GLfloat PI = 3.1415926;
GLfloat Fd = 5.0;            //fusion distance  
GLfloat RealScreenToEyeDistance = 1.0;
GLfloat R = Fd / RealScreenToEyeDistance;    //������ R =  Fd / RealScreenToEyeDistance  
GLfloat Sd = 0.05;                        //����֮��ľ���  
GLfloat aspect = 1.0;                        //gluLookAt��������Ĳ���  
GLfloat fovy = 60.0;                        //�Ž�  
GLfloat f = 1 / tan((fovy * PI) / (2 * 180));    //f=ctg(fovy/2);  

//�����ȵľ���ģ����ͼ����ͶӰ����  
GLfloat LeftModelViewMatrix[16] =
{
	1.0, 0.0, 0.0, 0.0,
	0.0, 1.0, 0.0, 0.0,
	0.0, 0.0, 1.0, 0.0,
	Sd * R / 2.0, 0.0, 0.0, 1.0
};

GLfloat LeftProjectMatrix[16] =
{
	1.0, 0.0, 0.0, 0.0,
	0.0, 1.0, 0.0, 0.0,
	0.0, 0.0, 1.0, 0.0,
	-(Sd * f) / (2.0 * Fd * aspect), 0.0, 0.0, 1.0
};

GLfloat RightModelViewMatrix[16] =
{
	1.0, 0.0, 0.0, 0.0,
	0.0, 1.0, 0.0, 0.0,
	0.0, 0.0, 1.0, 0.0,
	-Sd * R / 2.0, 0.0, 0.0, 1.0
};

GLfloat RightProjectMatrix[16] =
{
	1.0, 0.0, 0.0, 0.0,
	0.0, 1.0, 0.0, 0.0,
	0.0, 0.0, 1.0, 0.0,
	(Sd * f) / (2.0 * Fd * aspect), 0.0, 0.0, 1.0
};

//for the use of rotating  
static GLfloat spin = 0.0;

void init(void)
{
	GLfloat mat_diffuse[] = { 1.0, 1.0, 0.0 };
	GLfloat mat_specular[] = { 0.8, 0.8, 0.0, 1.0 };
	GLfloat mat_shininess[] = { 300. };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 0.0 };
	GLfloat light_ambient[] = { 0.7, 0.2, 0.2, 1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}
void display(void)
{
	GLfloat matrix[16] = { 0. };

	glColorMask(1.0, 1.0, 1.0, 1.0);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClearDepth(1.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	//---------------------------------------------------------------------------------------------  
	//Left View port  
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	{
		glGetFloatv(GL_PROJECTION_MATRIX, matrix);
		glLoadIdentity();
		glMultMatrixf(LeftProjectMatrix);
		glMultMatrixf(matrix);
		{
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glTranslated(0.0, 0.0, -Fd);
			glPushMatrix();
			{
				glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
				glLoadIdentity();
				glMultMatrixf(LeftModelViewMatrix);
				glMultMatrixf(matrix);
				glColorMask(1.0, 0.0, 0.0, 1.0);
				/**//*
					*  ���������Vp
					*  �任����Ļ���꣺Vp'= LeftProjectMatrix��Mp �� LeftModelViewMatrix��Mv �� Mr��Vp
					*/
				glPushMatrix();
				{
					glRotatef(spin, 0.0, 1.0, 0.0);
					glutSolidTeapot(1.0);
				}
				glPopMatrix();
			}
		}
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
	}
	glPopMatrix();
	glFlush();

	//---------------------------------------------------------------------------------------------  
	//Right View port  
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	{
		glGetFloatv(GL_PROJECTION_MATRIX, matrix);
		glLoadIdentity();
		glMultMatrixf(RightProjectMatrix);
		glMultMatrixf(matrix);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		{
			glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
			glLoadIdentity();
			glMultMatrixf(RightModelViewMatrix);
			glMultMatrixf(matrix);

			glColorMask(0.0, 1.0, 1.0, 1.0);
			glClearDepth(1.0);
			glClear(GL_DEPTH_BUFFER_BIT);
			/**//*
				*  ���������Vp
				*    �任����Ļ���꣺Vp'= RightProjectMatrix��Mp�� RightModelViewMatrix��Mv �� Mr��Vp
				*/
			glPushMatrix();
			{
				glRotatef(spin, 0.0, 1.0, 0.0);
				glutSolidTeapot(1.0);
				//glutSolidSphere(1.0, 20, 5);  
			}
		}
		glPopMatrix();

		glMatrixMode(GL_PROJECTION);
	}
	glPopMatrix();
	glFlush();

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	if (h == 0)
	{
		h = 1;
	}
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//ͶӰ����Mp  
	gluPerspective(fovy, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
}
void spinDisplay(void)
{
	spin = spin + 1.0;
	if (spin > 360.0)
	{
		spin = spin - 360.0;
	}
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(spinDisplay);
	glutMainLoop();
	return 0;
}
