#define GL_GLEXT_PROTOTYPES
#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "glm.cpp"
#include "glm.h"
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp" 
#include <cstdio>
#include<cstdlib>
#include "imageloader.h"
#include "imageloader.cpp"
#include "text3d.h"
using namespace std;
enum {X,Y,Z};
class Vector3D
{
	private:
		union 
		{
			float m_vVec[3];
			struct
			{
				float x;
				float y;
				float z;
			};
		};
};
#define PI 3.141592653589
#define DEG2RAD(deg) (deg * PI / 180)
typedef struct sAxisAlignedBoundingBox {
	Vector3D bounds[8];
	Vector3D max, min;
} AxisAlignedBoundingBox;

char s[1];
char s1[1];
int num;
int life=3;
int t1=9,t2=14;
int horz,vert;
float changey=0.0;
int flag=0;
int gazeno=0;
GLfloat dim[3];
float ball_x = 1.0f;
float ball_y = 0.0f;
float ball_velx = 0.01f;
float ball_vely = 0.02f;
float ball_rad = 0.2f;
float box_len = 4.0f;
float tri_x = 0.0f;
float tri_y = 0.0f;
char temp[50];
float _scale=0.5f;
const char* str="Game Over";

//float theta = 0.0f;
int down=0;
int jump=0;
int pindx=-1,indx=-1;
int thirdp=0;
int tileview=0;
int block=0;
int roboup=0;
int incr=1;
int upview=0;
//float xco=0.0f,zco=0.0f;
float intr=0;
//float theta = 0.0f; 
//float angle = 0.0f; 
Vector3D size,center;
GLMmodel *mod = NULL ;
GLMmodel *mod1 = NULL;
GLMmodel *mod2 =NULL;
GLMmodel *coin = NULL;
int g=0,k=-1,tower=0,person=0;
int pause1=0;
//int h,v,numr=0;
int gtheta = 0;
float move_x=0.0f,move_y=0.0f,move_z=0.0f;
// angle of rotation for the camera direction
float angle=0.0;
float angle1=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;
//float lx=0.0f,lz=-2.2f;
// XZ position of the camera
//float cam_x=1.5f,cam_y=2.5f,cam_z=6.2f;
float cam_x=1.5f,cam_y=1.2f,cam_z=7.0f;
//int flagx=0;
//int flagz=0;
float lookx,looky,lookz,facex,facey=0.0f,facez;
float go_y=0.0f;
int fall=0,win=0;
int col0=0,col1=0,col2=0,col3=0;
Vector3D vtr;
AxisAlignedBoundingBox box1;
AxisAlignedBoundingBox box2;
int count1=0,count2=0;
// Function Declarations
void drawScene();
void update(int value);
void drawBox();
//void drawBall(float rad);
//void drawTriangle();
void initRendering();
void handleResize(int w, int h);
void handleKeypress1(unsigned char key, int x, int y);
void handleKeypress2(int key, int x, int y);
void handleMouseclick(int button, int state, int x, int y);
void mouseWheel(int, int, int, int);
void somerand();
void GetOGLPos(int button, int state,int x, int y);
void motion(int x,int y);
void jump_func(int value);
void view();
int movewithtile(int ht,int vt);
void checkvoid(int ht,int vt);

void drawAxisAlignedBoundingBox(AxisAlignedBoundingBox box);
AxisAlignedBoundingBox boundbox(/*GLMmodel* mod,*/ AxisAlignedBoundingBox box,float ht, float cy, float vt, float h);


//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
			0,                            //0 for now
			GL_RGB,                       //Format OpenGL uses for image
			image->width, image->height,  //Width and height
			0,                            //The border of the image
			GL_RGB, //GL_RGB, because pixels are stored in RGB format
			GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
			//as unsigned numbers
			image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

GLuint _textureId;
GLuint _textureId2;
int hrand[15],vrand[15];
int kr,m,ok;
void somerand()
{
	kr=rand()%15;
	//kr=1;
	for(m=0;m<kr;m++)
	{
		hrand[m]=rand()%9;
		vrand[m]=rand()%14;
		if(hrand[m]==1 && vrand[m]==1)
		{
			hrand[m]=2;
			vrand[m]=2;
		}
	}
	m=0;
}
void cleanup() {
	t3dCleanup();
}

void drawAxisAlignedBoundingBox(AxisAlignedBoundingBox box) {
	glPushAttrib(GL_LIGHTING_BIT | GL_POLYGON_BIT);

	glEnable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHTING);

	glColor3f(1.0f, 1.0f, 0.0f);

	glBegin(GL_LINE_LOOP);
	glVertex3f(box.bounds[0].x, box.bounds[0].y, box.bounds[0].z);
	glVertex3f(box.bounds[1].x, box.bounds[1].y, box.bounds[1].z);
	glVertex3f(box.bounds[2].x, box.bounds[2].y, box.bounds[2].z);
	glVertex3f(box.bounds[3].x, box.bounds[3].y, box.bounds[3].z);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(box.bounds[4].x, box.bounds[4].y, box.bounds[4].z);
	glVertex3f(box.bounds[5].x, box.bounds[5].y, box.bounds[5].z);
	glVertex3f(box.bounds[6].x, box.bounds[6].y, box.bounds[6].z);
	glVertex3f(box.bounds[7].x, box.bounds[7].y, box.bounds[7].z);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(box.bounds[0].x, box.bounds[0].y, box.bounds[0].z);
	glVertex3f(box.bounds[5].x, box.bounds[5].y, box.bounds[5].z);
	glVertex3f(box.bounds[6].x, box.bounds[6].y, box.bounds[6].z);
	glVertex3f(box.bounds[1].x, box.bounds[1].y, box.bounds[1].z);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(box.bounds[4].x, box.bounds[4].y, box.bounds[4].z);
	glVertex3f(box.bounds[7].x, box.bounds[7].y, box.bounds[7].z);
	glVertex3f(box.bounds[2].x, box.bounds[2].y, box.bounds[2].z);
	glVertex3f(box.bounds[3].x, box.bounds[3].y, box.bounds[3].z);
	glEnd();

	glPopAttrib();
}
// Global Variables


void GetOGLPos(int button, int state,int x, int y)
{

	if(gazeno%2==1){

		if(state == GLUT_DOWN)
		{
			if(button == GLUT_LEFT_BUTTON)
			{
				GLint viewport[4];
				GLdouble modelview[16];
				GLdouble projection[16];
				GLfloat winX, winY, winZ;
				GLdouble posX, posY, posZ;

				glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
				glGetDoublev( GL_PROJECTION_MATRIX, projection );
				glGetIntegerv( GL_VIEWPORT, viewport );

				winX = (float)x;
				winY = (float)viewport[3] - (float)y;
				glReadPixels( x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );

				gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);
				vtr.x=posX;
				vtr.y=posY;
				vtr.z=posZ;

			}
			float len=sqrt((vtr.x-cam_x)*(vtr.x-cam_x)+(vtr.y-cam_y)*(vtr.y-cam_y)+(vtr.z-cam_z)*(vtr.z-cam_z));
			if(button==3)
			{
				// Zoom in
				//if(vtr.x>cam_x && vtr.y > cam_y && vtr.z>cam_z){
				cam_x+=0.1*(vtr.x-cam_x)/len;
				cam_y+=0.1*(vtr.y-cam_y)/len;
				cam_z+=0.1*(vtr.z-cam_z)/len;
				//}
			}
			if(button==4)
			{
				// Zoom out
				//if(vtr.x>cam_x && vtr.y > cam_y && vtr.z>cam_z){
				cam_x-=0.1*(vtr.x-cam_x)/len;
				cam_y-=0.1*(vtr.y-cam_y)/len;
				cam_z-=0.1*(vtr.z-cam_z)/len;
				//}
			}
		}
	}
}
void motion(int x,int y)
{
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
	glGetDoublev( GL_PROJECTION_MATRIX, projection );
	glGetIntegerv( GL_VIEWPORT, viewport );

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels( x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );

	gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);
	vtr.x=posX;
	vtr.y=posY;
	vtr.z=posZ;
	//glutPostRedisplay();


}
int nojump=0;
float hgt=0.0,minh=0.0f,maxh=0.5f;
void jump_func(int value)
{
	if(jump==1)
	{
		if(hgt<maxh && nojump==0)
			hgt+=0.05f;
		else if(hgt>=maxh && nojump==0)
			nojump=1;
		else if(nojump==1 && hgt>0.0f)
		{
			printf("decr\n");
			hgt-=0.05f;
		}
		else if(hgt<=minh)
		{
			printf("neeche\n");
			jump=0;
			nojump=0;
		}
		move_z+=0.03f;
		move_y=hgt;
		printf("heght:%f\n",hgt);
		//printf("%f\n...........\n",move_y);
	}
	glutTimerFunc(1, jump_func, 0);

}

int main(int argc, char **argv) {

	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	int w = glutGet(GLUT_SCREEN_WIDTH);
	int h = glutGet(GLUT_SCREEN_HEIGHT);
	int windowWidth = w * 2 / 3;
	int windowHeight = h * 2 / 3;
	//_scale = computeScale(STRS);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition((w - windowWidth) / 2, (h - windowHeight) / 2);

	glutCreateWindow("CSE251_sampleCode");  // Setup the window
	initRendering();
	somerand();
	// Register callbacks
	//InitMesh();
	glutDisplayFunc(drawScene);
	glutIdleFunc(drawScene);
	glutKeyboardFunc(handleKeypress1);
	glutSpecialFunc(handleKeypress2);
	//	   glutMouseFunc(handleMouseclick);
	//glutPassiveMotionFunc(GetOGLPos);
	glutMouseFunc(GetOGLPos);
	glutMotionFunc(motion);
	//glutMouseWheelFunc(mouseWheel);
	glutReshapeFunc(handleResize);
	glutTimerFunc(90, update, 0);
	glutTimerFunc(1, jump_func, 0);


	glutMainLoop();
	return 0;
}
AxisAlignedBoundingBox boundbox(/*GLMmodel* mod,*/ AxisAlignedBoundingBox box,float ht, float cy, float vt, float h)
{
	//glmDimensions(mod, dim);
	//AxisAlignedBoundingBox box;
	/*box.max.x = dim[0] / 2.0f, box.min.x = -1.0f * box.max.x;
	  box.max.y = dim[1] / 2.0f, box.min.y = -1.0f * box.max.y;
	  box.max.z = dim[2] / 2.0f, box.min.z = -1.0f * box.max.z;
	 *///printf("%f %f %f\n",dim[0],dim[1],dim[2]);
	//printf("%f %f %f %f\n",box.max.x,box.min.x,box.max.y,box.min.y);


	GLfloat
		minx, maxx,
		miny, maxy,
		minz, maxz;

	//|| (lookz+4.2<-1.7+(3/*vert tile from -1.7 */-1)*0.45 && lookz+4.2>-1.7+(2-1)*0.45 
	//&& lookx+1.7 > -2+(3-1)*0.45 && lookx+1.7 <-2+(4/*horz tile from -2 */ -1)*0.45)
	minx=-2+(ht-1-1)*0.45+0.2;
	maxx=-2+(ht-1)*0.45+0.2;
	miny=cy-h;maxy=cy+h;
	minz=-1.7+(vt-1-1)*0.45;
	maxz=-1.7+(vt-1)*0.45;
	/*minx=-l;maxx=l;
	  miny=1-h;maxy=1+h;
	  minz=-b;maxz=b;
	 */
	/*
	   maxx = minx = mod->vertices[3 + X];
	   maxy = miny = mod->vertices[3 + Y];
	   maxz = minz = mod->vertices[3 + Z];
	   int i;
	   for (i = 1; i <= mod->numvertices; i++) {
	   if (maxx < mod->vertices[3 * i + X])
	   maxx = mod->vertices[3 * i + X];
	   if (minx > mod->vertices[3 * i + X])
	   minx = mod->vertices[3 * i + X];

	   if (maxy < mod->vertices[3 * i + Y])
	   maxy = mod->vertices[3 * i + Y];
	   if (miny > mod->vertices[3 * i + Y])
	   miny = mod->vertices[3 * i + Y];

	   if (maxz < mod->vertices[3 * i + Z])
	   maxz = mod->vertices[3 * i + Z];
	   if (minz > mod->vertices[3 * i + Z])
	   minz = mod->vertices[3 * i + Z];
	   }
	   size.x=maxx-minx;
	   size.y=maxy-miny;
	   size.z=maxz-minz;
	   center.x=(minx+maxx)/2;
	   center.y=(miny+maxy)/2;
	   center.z=(minz+maxz)/2;
	 */
	//glTranslatef(center.x,center.y,center.x);
	// maxy-miny, maxz-minz);
	//printf("%f %f %f\n",maxx-minx, maxy-miny, maxz-minz);
	box.min.x=minx;
	box.min.y=miny;
	box.min.z=minz;
	box.max.x=maxx;
	box.max.y=maxy;
	box.max.z=maxz;

	//printf("1: %f %f %f %f %f %f\n",box.min.x,box.min.y,box.min.z,box.max.x,box.max.y,box.max.z);

	box.bounds[0].x=maxx;
	box.bounds[0].y=maxy;
	box.bounds[0].z=maxz;
	box.bounds[1].x=minx;
	box.bounds[1].y=maxy;
	box.bounds[1].z=minz;
	box.bounds[2].z=minz;
	box.bounds[2].x=minx;
	box.bounds[2].y=miny;
	box.bounds[3].x=maxx;
	box.bounds[3].y=miny;
	box.bounds[3].z=minz;
	box.bounds[4].x=maxx;
	box.bounds[4].y=miny;
	box.bounds[4].z=maxz;
	box.bounds[5].x=maxx;
	box.bounds[5].y=maxy;
	box.bounds[5].z=maxz;
	box.bounds[6].x=minx;
	box.bounds[6].y=maxy;
	box.bounds[6].z=maxz;
	box.bounds[7].x=minx;
	box.bounds[7].y=miny;
	box.bounds[7].z=minz;

	/*box.bounds[0] = Vector3D(box.max.x, box.max.y, box.min.z);
	  box.bounds[1] = Vector3D(box.min.x, box.max.y, box.min.z);
	  box.bounds[2] = Vector3D(box.min.x, box.min.y, box.min.z);
	  box.bounds[3] = Vector3D(box.max.x, box.min.y, box.min.z);
	  box.bounds[4] = Vector3D(box.max.x, box.min.y, box.max.z);
	  box.bounds[5] = Vector3D(box.max.x, box.max.y, box.max.z);
	  box.bounds[6] = Vector3D(box.min.x, box.max.y, box.max.z);
	  box.bounds[7] = Vector3D(box.min.x, box.min.y, box.max.z);
	 */
	//drawAxisAlignedBoundingBox(box);
	return box;




}
void view()
{

	if(indx==3)//left
	{
		lookx=-move_z;
		if(thirdp%2==1)
		{
			lookx=-(move_z-0.8f);
		}
		facex=lookx-2.0f;
		lookz=move_x;//+1.0f;
		facez=lookz;
	}
	if(indx==1)//right
		//if(flagx==1)
	{
		lookx=move_z;
		facex=lookx+1.0f;
		if(thirdp%2==1)
		{
			lookx=(move_z-0.8f);
			facex=lookx+1.5f;
		}
		lookz=-move_x;//+1.0f;
		facez=lookz;
	}
	if(indx==0)//down
		//if(flagz==1)
	{
		lookx=move_x;
		lookz=move_z;
		if(thirdp%2==1)
		{
			lookz=(move_z-0.6f);
		}
		facex=lookx;
		facez=lookz+1.0f;
	}
	if(indx==2)//up
		//if(flagz==-1)
	{
		lookz=-move_z;
		if(thirdp%2==1)
		{
			lookz=-(move_z-0.6f);
		}
		lookx=-move_x;
		facex=lookx;
		facez=lookz-1.0f;
	}

	//printf("%f %f\n",move_x,move_z);
}
int movewithtile(int ht,int vt)
{

	if((lookz+4.2<-1.7+(vt/*vert tile from -1.7 */-1)*0.45 && lookz+4.2>-1.7+(vt-1-1)*0.45 
				&& lookx+1.7 > -2+(ht-1-1)*0.45 && lookx+1.7 <-2+(ht/*horz tile from -2 */ -1)*0.45)
	  )
	{
		printf("......... %f\n",-0.1+changey);
		if( -0.1+changey<0.5)
		{
			//ontile=1;
			roboup=1;
		}
		if(-0.1+changey>0.5)
		{
			fall=1;
		}
		//if(ontile==0 && roboup==0 && -0.1+changey>0.5 ){fall=1;}
		/*
		   if(ontile=1 && 
		   if(-0.1+changey>0.5)
		   {tileup=1;}

		   if(roboup==0 && tileup==1){fall=1;}
		 *//*if(-0.1+changey>0.5 && move_y>0.5)
		     {
		     fall=1;
		     }
		    */

		return 1;
	}
	//else if(move_y>0.5){fall=1;}
	return 0;
	/*else{

	  roboup=0;
	  move_y=0;
	  return 0;
	  }*/

}
void checkvoid(int ht,int vt)
{
	if(lookz+4.2<-1.7+(vt/*vert tile from -1.7 */-1)*0.45 && lookz+4.2>-1.7+(vt-1-1)*0.45 
			&& lookx+1.7 > -2+(ht-1-1)*0.45 && lookx+1.7 <-2+(ht/*horz tile from -2 */ -1)*0.45)
	{
		fall=1;
	}
	if(lookz+4.2<-1.7+(10/*vert tile from -1.7 */-1)*0.45 && lookz+4.2>-1.7+(10-1-1)*0.45 
			&& lookx+1.7 > -2-changey+(5-1-1)*0.45 && lookx+1.7 <-2-changey+(5/*horz tile from -2 */ -1)*0.45)
	{
		fall=1;
	}
if(lookz+4.2<-1.7+(12/*vert tile from -1.7 */-1)*0.45 && lookz+4.2>-1.7+(12-1-1)*0.45 
			&& lookx+1.7 > -2-changey+(7-1-1)*0.45 && lookx+1.7 <-2-changey+(8/*horz tile from -2 */ -1)*0.45)
	{
		fall=1;
	}

if(lookz+4.2<-1.7+changey+(1/*vert tile from -1.7 */-1)*0.45 && lookz+4.2>-1.7+changey+(1-1-1)*0.45 
			&& lookx+1.7 > -2+(6-1-1)*0.45 && lookx+1.7 <-2+(6/*horz tile from -2 */ -1)*0.45)
	{
		fall=1;
	}

}


// Function to draw objects on the screen
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0f, 1.0f, 1.0f);
	/*GLfloat mat_specular[] = {0.5, 0.5, 0.5, 1.0};
	  GLfloat mat_shininess[] = { 10.0 };
	  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	  glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	  glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	  glEnable(GL_COLOR_MATERIAL);
	 *///Add ambient light
	//GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	view();
	//if(flagx==-1)
	/*if(person%2==0 && thirdp%2==0){
	  gluLookAt(5,0,3.5,0,0.8,0,0,1,0);
	  }*/
	//glutStrokeString(GLUT_STROKE_ROMAN, text);

	if(upview%2==0 && person%2==0 && thirdp%2==0 && tileview%2==0 && gazeno%2==0){	gluLookAt(	cam_x, cam_y, cam_z,
			//0.0f,0.0f,0.0f,
			//move_x-0.1f,0.0f,move_z-0.1f,
			cam_x+lx, 1.0f,  cam_z+lz,			
//lookx+1.7,0,lookz+4.2,
			0.0f, 1.0f,  0.0f);}
	//gluLookAt(-.3,0,0,0,0,0,0,1,0);

	if(upview%2==1){
		gluLookAt(1.5,2.5,6.3,
				1.5-0.5, 1.0f,  6.2-2.2,
				0.0f, 1.0f,  0.0f);}


	if(gazeno%2==1)
	{
		//	gluLookAt( vtr.x,vtr.y,vtr.z,0,0,0,0,1,0);
		gluLookAt( cam_x,cam_y,cam_z,vtr.x,vtr.y,vtr.z,0,1,0);
	}
	if(tileview%2==1){
		if(t1>9){t1=9;}
		if(t1<1){t1=1;}
		if(t2>14){t2=14;}
		if(t2<1){t2=1;}
		gluLookAt( (0.1)-2+(t1-1)*0.45, 0.0f , -2+(t2-1)*0.45,
				lookx+1.7, 0.0f,  lookz+4.2,
				0.0f, 1.0f,  0.0f);
	}
	else
		if(person%2==1 || thirdp%2==1){
			if(thirdp%2==1){looky=1.0f;}
			if(fall==1){looky=go_y;facey=looky;}
			gluLookAt(	lookx+1.7, looky-0.1f , lookz+4.2,
					facex+1.7,facey,  facez+4.2,
					0.0f, 1.0f,  0.0f);
			//printf("movex:%f movez:%f\n",move_x,move_z);
			//printf("lookx:%f lookz:%f\n",lookx+1.7,lookz+3.2);
			//printf("facex:%f facez:%f\n",facex+1.7,facez+3.2);
		}	

	if((lookx+1.7>2) ||(lookx+1.7<-2.3) || lookz+4.2>4.4 || lookz+4.2<-2
			//|| (lookz+4.2<-2+2*0.45 && lookx+1.7 > 2-1*0.45)
			|| (lookz+4.2<-2+2*0.45 && lookx+1.7 > -2+8*0.45)
			//|| (lookz+4.2<-1.7+(10/*vert tile from -1.7 */-1)*0.45 && lookz+4.2>-1.7+(9.5-1)*0.45 
			//&& lookx+1.7 > -2+(7-1)*0.45 && lookx+1.7 <-2+(8/*horz tile from -2 */ -1)*0.45)
			//|| (lookz+4.2<-1.7+(12/*vert tile from -1.7 */-1)*0.45 && lookz+4.2>-1.7+(11.5-1)*0.45 
			//&& lookx+1.7 > -2+(6.5-1)*0.45 && lookx+1.7 <-2+(7/*horz tile from -2 */ -1)*0.45)
			//|| (lookz+4.2<-1.7+(3/*vert tile from -1.7 */-1)*0.45 && lookz+4.2>-1.7+(2-1)*0.45 
			//&& lookx+1.7 > -2+(3-1)*0.45 && lookx+1.7 <-2+(4/*horz tile from -2 */ -1)*0.45)

	  ){printf("fall\n");
		fall=1;
	}
	if(lookz+4.2<-1.7+(2/*vert tile from -1.7 */-1)*0.45 && lookz+4.2>-1.7+(2-1-1)*0.45 
			&& lookx+1.7 > -2+(2-1-1)*0.45 && lookx+1.7 <-2+(2/*horz tile from -2 */ -1)*0.45)
{win=1;}

	if(lookz+4.2<-1.7+(13/*vert tile from -1.7 */-1)*0.45 && lookz+4.2>-1.7+(13-1-1)*0.45 
			&& lookx+1.7 > -2+(4-1-1)*0.45 && lookx+1.7 <-2+(4/*horz tile from -2 */ -1)*0.45)
{count1=1;}
	if(lookz+4.2<-1.7+(6/*vert tile from -1.7 */-1)*0.45 && lookz+4.2>-1.7+(6-1-1)*0.45 
			&& lookx+1.7 > -2+(6-1-1)*0.45 && lookx+1.7 <-2+(6/*horz tile from -2 */ -1)*0.45)
{count2=1;}
	//printf("%f %f.....................\n",lookx+1.7,lookz+4.2);
	checkvoid(8,10);
	checkvoid(9,3);
	//checkvoid(7,12);
	//checkvoid(4,3);
	//checkvoid(4,10);
	checkvoid(3,12);
	checkvoid(4,2);
	checkvoid(4,8);
	checkvoid(3,8);
	checkvoid(3,5);
		//AxisAlignedBoundingBox box2;
	//draw tiles blender
	/*
	   glPushMatrix();
	   if(tiles==NULL){
	   strcpy(temp,"tile_2.obj");
	   tiles = glmReadOBJ(temp);
	//tiles = glmReadOBJ("tile_2.obj");
	glmUnitize(tiles);
	glmFacetNormals(tiles);
	glmVertexNormals(tiles, 90.0);
	}
	glColor3f(1.0,0.0,0.0);

	//	glRotatef(20,1,0,0);
	//glTranslatef(0.0f,-0.3f,0.2f);
	glTranslatef(0.0f,0.0f,0.2f);

	//box1=boundbox(tiles,box1);
	glmDraw(tiles,GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
	//glmDraw(tiles,0);
	glPopMatrix();
	//printf("%f %f %f %d",move_x,move_z,dis,gtheta);
	//    glColor3f(1.0f, 0.0f, 0.0f);
	 */
	/*
	   float i=3.0;
	   while(i>=-3.0)
	   {
	   glPushMatrix();
	//glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glTranslatef(0.3,-0.5,i);
	glutSolidCube(0.2);
	glPopMatrix();
	i-=0.2;
	}
	 */
	//if(fall==0){
	drawBox();
	//}
	int hey=0;
	roboup=0;
	if(movewithtile(9,5)==1){hey=1;}
	if(hey!=1){
		if(movewithtile(8,14)==1){hey=1;}
		if(hey!=1){
			if(movewithtile(hrand[kr],vrand[kr])==1){hey=1;}
			if(hey!=1){
				if(movewithtile(hrand[kr-1],vrand[kr-1])==1){hey=1;}
				if(hey!=1)
					if(movewithtile(hrand[kr-2],vrand[kr-2])==1){hey=1;}
				if(hey!=1){
					roboup=0;
					if(jump!=1){move_y=0;}
					//ontile=0;
				}
			}
		}}

	glPushMatrix(); 
	//glTranslatef(0,-0.5,0);
	glTranslatef(1.7,0.0,4.2);
	glRotatef(gtheta,0,1,0);
	if(fall==1)
	{
		glTranslatef(move_x,go_y,move_z);
	}else
		glTranslatef(move_x,move_y,move_z);
	printf("y..%f z..%f\n",move_y,move_z);
	// Set the camera

	/*		gluLookAt(	cam_x, 0.0f, cam_z,
			0.0f,0.0f,0.0f,
	//move_x-0.1f,0.0f,move_z-0.1f,
	//	cam_x+lx, 0.0f,  cam_z+lz,
	0.0f, 1.0f,  0.0f);
	 */
	// printf("1: %f %f %f %f %f %f\n",box1.min.x,box1.min.y,box1.min.z,box1.max.x,box1.max.y,box1.max.z);
	//printf("%f %f",lookx+1.7,lookz+4.2);
	if ( (box1.min.x < lookx+1.7 &&  lookx+1.7 < box1.max.x)&& (box1.min.z < lookz+4.2 && lookz+4.2 < box1.max.z )) 
	{  
		if(indx==0)col0=1;
		if(indx==1)col1=1;
		if(indx==2)col2=1;
		if(indx==3)col3=1;
		printf("Collision\n");
	}
	else
	{   printf("NOCollision\n");

	}
	if ( (box2.min.x < lookx+1.7 &&  lookx+1.7 < box2.max.x)&& (box2.min.z < lookz+4.2 && lookz+4.2 < box2.max.z )) 
	{  
		if(indx==0)col0=1;
		if(indx==1)col1=1;
		if(indx==2)col2=1;
		if(indx==3)col3=1;
		printf("Collision\n");
	}
	else
	{   printf("NOCollision\n");

	}


	if(g%2==0)
	{


		if(!mod )
		{
strcpy(temp,"orig2.obj");
			mod = glmReadOBJ(temp);
			//mod = glmReadOBJ("orig2.obj");
			if(!mod) exit(0);
			glmUnitize(mod);
			glmFacetNormals(mod);
			glmVertexNormals(mod, 90.0);
			//float dimensions[3];
		}
		//box2=boundbox(mod,box2);
		//glRotatef(90,0,1,0);
		if(mod2){
			glmDelete(mod2);
			mod2=NULL;}
		ok=0;
		if(person%2==1 && indx==0)
		{ok=1;}
		if(ok!=1){
			glmDraw(mod, GLM_SMOOTH | GLM_MATERIAL);
		}	//glPopMatrix();
	}
	else if(g%2==1)
	{
		//glPushMatrix();

		if(mod)
		{glmDelete(mod);
			mod=NULL;}
		if(!mod2 )
		{
			strcpy(temp,"orig1.obj");
			mod2 = glmReadOBJ(temp);
			//mod2 = glmReadOBJ("orig1.obj");
			if(!mod2) exit(0);
			glmUnitize(mod2);
			glmFacetNormals(mod2);
			glmVertexNormals(mod2, 90.0);
			//glmDimensions(mod2, dim);
			//printf("%f %f %f\n",dim[0],dim[1],dim[2]);
		}
		//box2=boundbox(mod2,box2);
		//glRotatef(theta,0.0,1.0,0.0);
		//glTranslatef(theta,0.0,0.0);
		//glRotatef(90,0,1,0);
		ok=0;
		if(person%2==1 && indx==0)
		{ok=1;}
		if(ok!=1){
			glmDraw(mod2, GLM_SMOOTH | GLM_MATERIAL);
		}
	}

	//printf("2: %f %f %f %f %f %f\n",box2.min.x+move_x,box2.min.y,box2.min.z+move_z,box2.max.x+move_x,box2.max.y,box2.max.z+move_z);
	// printf("2: %f %f %f %f %f %f\n",box2.min.x,box2.min.y,box2.min.z,box2.max.x,box2.max.y,box2.max.z);
	// printf("%f %f\n",move_x,move_z);
	glPopMatrix();
	//if(fall==1){drawBox();}
	// printf("1: %f %f %f %f %f %f\n",box1.min.x,box1.min.y,box1.min.z,box1.max.x,box1.max.y,box1.max.z);


	// printf("2: %f %f %f %f %f %f",box2.min.x,box2.min.y,box2.min.z,box2.max.x,box2.max.y,box2.max.z);
	/*
	   if ( box1.min.x > box2.max.x || box2.min.x > box1.max.x
	   ||box1.min.y > box2.max.y || box2.min.y > box1.max.y
	   ||box1.min.z > box2.max.z || box2.min.z > box1.max.z ) 
	   {  
	   printf("Collision\n");
	   }
	   else
	   {   printf("NOCollision\n");
	   }
	 */
num=count1+count2;
s[0]=(char)num+48;
s[1]='\0';
//printf(".........................%s\n",s);
//itoa(count1+count2,buffer,10);
	//glColor3f(0.3f, 1.0f, 0.3f);

char score[10]="Score:";
strcat(score,s);
glPushMatrix();
	glScalef(0.2, 0.2, 0.2);
	glTranslatef(-1, 1, -10);
t3dDraw3D(score,1,0,0.2f);
	glTranslatef(0, 1, 0);
s1[0]=(char)life+48;
s1[1]='\0';
char lyf[10]="Life:";
strcat(lyf,s1);
t3dDraw3D(lyf,1,0,0.2f);
	glPopMatrix();
glPushMatrix();

	glScalef(_scale, _scale, _scale);
	glTranslatef(vtr.x, vtr.y, vtr.z);
if(win==1 && count1==1 && count2==1){ t3dDraw3D("You win !! :D ",0,0,0.2f);
}
	glPopMatrix();

if(fall==1 && win==0){
if(life==1){
life--;
	t3dDraw3D(str,0,0,0.2f);}

if(life>1){
fall=0;
go_y=0;
move_x=0.0f;move_y=0.0f;move_z=0.0f;
lookx=0.0f;looky=0.0f;lookz=0.0f;
 down=0;
 jump=0;
 pindx=-1,indx=-1;
 thirdp=0;
 tileview=0;
 block=0;
 roboup=0;
 incr=1;
 upview=0;
 flag=0;
 gazeno=0;
 angle=0.0;
angle1=0.0;
life--;
}
printf("lief........................... %d\n",life);
}



	glFlush();
	glutSwapBuffers();

}

// Function to handle all calculations in the scene
// updated evry 10 milliseconds
void update(int value) {
	
if(pause1%2==0){
		if(fall==1 && win==0){go_y-=0.1f;}
		//printf("chng:%f\n",changey);
		if(flag==0){
			changey+=0.05;}
		if(changey>0.8)
		{flag=1;}
		if(flag==1)
		{changey-=0.05;}
		if(changey<0)
		{flag=0;
			somerand();
		}
		if(roboup==1)
		{
			move_y=changey-0.1f;
		}
	}
		glutTimerFunc(90, update, 0);
}

void drawBox() {
	glEnable(GL_COLOR_MATERIAL);    // Enable coloring

	glDisable(GL_LIGHTING);
	//draw water
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);

	//Bottom
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(  80, -1, -20 );
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(  40,  -1, 20 );
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f( -20, -1, -20 );
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f( -40, -1, 80 );
	glEnd();
	glDisable(GL_TEXTURE_2D);

		if(!coin )
		{
strcpy(temp,"coin.obj");
			coin = glmReadOBJ(temp);
			if(!coin) exit(0);
			glmUnitize(coin);
			glmFacetNormals(coin);
			glmVertexNormals(coin, 90.0);
		}


	glPushMatrix();
	glTranslatef(0,-0.5,1);

	//numr=0;
	horz=0;
	float xb,zb,l=0.2,h=0.05,b=0.2;
	xb=-2;
	while(xb<=2)
	{
		vert=0;
		horz++;
		zb=-3;
		while(zb<=3)
		{
			vert++;

			/*while(numr<10){
			  h=rand()%21;
			  v=rand()%27;
			  numr++;
			  }*/
			//printf("h:%d v:%d \n",horz,vert);
			/*if(horz%6==0){
			  printf("h%6:%d v:%d %f\n",horz,vert,changey[horz][vert]);
			  }
			  if(vert%4==0){
			  printf("h:%d v%4:%d %f\n",horz,vert,changey[horz][vert]);
			  }*/
			ok=0;
int ok1=0;
			glPushMatrix();
			//for(m=0;m<kr;m++)
			//{
			//printf("%d %d %d\n",m,hrand[m],vrand[m]);
if((horz==3 && vert==10)||(horz==6 && vert==12))
{
			glTranslatef(xb+changey,-0.1,zb);
printf("%f %f %f..................\n",xb+changey,-0.1,zb);
ok1=1;		
}
if(horz==4 && vert==1)
{
			glTranslatef(xb,-0.1,zb+changey);
ok1=1;
}
	//moving tiles
			if((horz==hrand[kr] && vert==vrand[kr])
					|| (horz==hrand[kr-1] && vert==vrand[kr])
					|| (horz==8 && vert==14)
					|| (horz==9 && vert==5)
					|| (horz==hrand[kr-2] && vert==vrand[kr-2]))
				//if(horz%6==0 && vert%4==0 )
				//if(numr<10 && horz==h && vert==v)
			{
if(ok1!=1){
				ok=1;
				glTranslatef(xb,-0.1+changey,zb);

	}					}
		if(ok==0 && ok1!=1){
			glTranslatef(xb,-0.1,zb);
		}
		ok=0;
		if((horz==2 && vert ==5 )|| (horz==2 && vert==8) ||
				(horz==4 && vert==2) || (horz==3 && vert==8) ||
				(horz==2 && vert==12) || (horz==7 && vert==12) ||
				(horz==4 && vert==10) || (horz==4 && vert==3) ||
				(horz==8 && vert==10) || (horz==9 && vert==3))
		{
			//printf("%f %f\n",-2+8*0.45,-3+0*0.45);
			ok=1;
		}
		block=0;
		if(ok==0)
		{
			if((horz==6 && vert==11) /*|| (horz==8 && vert==4)*/){h=1.0;
				block=1;
				box1=boundbox(box1,horz,-0.1,vert,h);
			}
			else if((horz==8 && vert==4) /*|| (horz==8 && vert==4)*/){h=1.0;
				block=1;
				box2=boundbox(box2,horz,-0.1,vert,h);
			}
			else{h=0.05;}
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, _textureId);

			//Bottom
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			//Front-white
			glBegin(GL_POLYGON);
			glColor3f(   0.0,  0.0, 0.0 );
			//glColor3f(   1.0,  1.0,  0.0 );
			glTexCoord2f(0.0f, 0.0f);
			if(block==1){glVertex3f(l,0,b);}else
				glVertex3f(  l, -h, b );
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(  l,  h, b );
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f( -l,  h, b );
			glTexCoord2f(0.0f, 1.0f);
			if(block==1){glVertex3f(-l,0,b);}else
				glVertex3f( -l, -h, b );
			glEnd();

			// Purple side - RIGHT
			glBegin(GL_POLYGON);
			glColor3f(   0.0,  0.0, 0.0 );
			//glColor3f(   1.0,  1.0, 1.0 );
			//glColor3f(  1.0,  0.0,  1.0 );
			glTexCoord2f(0.0f, 0.0f);
			if(block==1){glVertex3f(l,0,-b);}else
				glVertex3f( l, -h, -b );
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f( l,  h, -b );
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f( l,  h,  b );
			glTexCoord2f(0.0f, 1.0f);
			if(block==1){glVertex3f(l,0,b);}else
				glVertex3f( l, -h,  b );
			glEnd();

			// Green side - LEFT
			glBegin(GL_POLYGON);
			glColor3f(   1.0,  1.0, 1.0 );
			//glColor3f(   0.0,  0.0, 0.0 );
			//glColor3f(   1.0,  0.0,  0.0 );
			glTexCoord2f(0.0f, 0.0f);
			if(block==1){glVertex3f(-l,0,b);}else
				glVertex3f( -l, -h,  b );
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f( -l,  h,  b );
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f( -l,  h, -b );
			glTexCoord2f(0.0f, 1.0f);
			if(block==1){glVertex3f(-l,0,-b);}else
				glVertex3f( -l, -h, -b );
			glEnd();

			// Blue side - TOP
			glBegin(GL_POLYGON);
			glColor3f(   1.0,  1.0, 1.0 );
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(  l,  h,  b );
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(  l,  h, -b );
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f( -l,  h, -b );
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f( -l,  h,  b );
			glEnd();

			//Back
			glBegin(GL_POLYGON);
			glColor3f(   1.0,  1.0, 1.0 );
			//glColor3f(   1.0,  1.0,  0.0 );
			glTexCoord2f(0.0f, 0.0f);
			if(block==1){glVertex3f(-l,0,-b);}else
				glVertex3f( -l, -h, -b );
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f( -l,  h, -b );
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(  l,  h, -b );
			glTexCoord2f(0.0f, 1.0f);
			if(block==1){glVertex3f(l,0,-b);}else
				glVertex3f(  l, -h, -b );
			glEnd();



			// Red side - BOTTOM
			glBegin(GL_POLYGON);
			glColor3f(   1.0,  1.0,  1.0 );
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(  l, h, -b );
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(  l, h,  b );
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f( -l, h,  b );
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f( -l, h, -b );
			glEnd();
if((horz==4 && vert==13)|| (horz==5&&vert==6)){
glDisable(GL_TEXTURE_2D);
glColor3f(   1.0,  0.0,  1.0 );
if(count1==0 && horz==4 && vert==13){
			glmDraw(coin, GLM_SMOOTH | GLM_MATERIAL);
}

if(count2==0 && horz==5 && vert==6){
			glmDraw(coin, GLM_SMOOTH | GLM_MATERIAL);
}

}
		}
		glPopMatrix();
		zb=zb+0.45;
	}
	//xb+=0.222;
	xb+=0.45;
}


glPopMatrix();
glDisable(GL_TEXTURE_2D);
//printf("horz:%d  vert:%d\n",horz,vert);		
glDisable(GL_COLOR_MATERIAL);    // Enable coloring
glEnable(GL_LIGHTING);

}



// Initializing some openGL 3D rendering options
void initRendering() {

	glEnable(GL_DEPTH_TEST);        // Enable objects to be drawn ahead/behind one another
	glEnable(GL_COLOR_MATERIAL);    // Enable coloring
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);   // Setting a background color
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat lightpos1[] = {lookx+1.7, 0.0, lookz+4.2, 0.0};
glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightpos1 );
glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180); // angle is 0 to 180
glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 78); 
	glShadeModel(GL_SMOOTH);
	//glEnable(GL_LIGHT1);
	glEnable(GL_CULL_FACE);
	GLfloat lightpos[] = {0.5, 1.0, 1.0, 0.0};
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
	Image* image = loadBMP("images.bmp");
	_textureId = loadTexture(image);
	Image* image1 = loadBMP("water.bmp");
	_textureId2 = loadTexture(image1);
	delete image;
	delete image1;
	t3dInit();
}

// Function called when the window is resized
void handleResize(int w, int h) {

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)w / (float)h, 0.1f, 200.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void handleKeypress1(unsigned char key, int x, int y) {

if(key==112)//p pause
{
pause1++;
}
	if (key == 27) {
		cleanup();
		exit(0);     // escape key is pressed
	}
	else if (key == 119) //w, rotating view
	{
		tower++;
	}
	else if (key == 102) //f first person view
	{
		person++;
	}
	else if(key ==116)//t third person view
	{
		thirdp++;
	}
	else if(key ==108)//l tile view
	{
		tileview++;
	}

	if(key==105) //i inc speed of robot
	{
		if(incr>=1){
			incr++;
		}
		if(incr<1)
		{
			incr+=0.1f;
		}
	}
	if(key==111) //o dec speed of robot
	{
		if(incr>1){
			incr--;
		}
		if(incr<=1){incr-=0.1f;}
	}
	if(key==117)//u , up(tower) view
	{
		upview++;
	}

	if(key==119)//w tile inc
	{
		t2--;
	}
	if(key==122)//z
	{
		t2++;
	}
	if(key==115)//s
	{
		t1++;
	}
	if(key==97)//a
	{
		t1--;
	}
	if(key==103)//g helicopter view
	{
		gazeno++;
	}
	if(key==106){//j
		if(jump==1)
		{jump=0;}
		else
			jump=1;
		//if(jump==2){jump=0;}
		//jump_func();
	}


}

void handleKeypress2(int key, int x, int y) {
if(win!=1){
if(pause1%2==0){
	float fraction = 0.1f;
	printf("indexx: %d\n",indx);

	if (key == GLUT_KEY_LEFT)
	{

		if(col3==0){
			//flagz=0;
			//flagx=-1;
			col0=0;
			col1=0;
			col2=0;
			col3=0;
			if(tower%2==1){
				angle -= 0.01f;
				lx = sin(angle);
				lz = -cos(angle);
			}
			/*else if(tower%2==0){
			  if(person%2==1)
			  {
			  down=0;
			  angle1 -= 0.03f;
			  lx = sin(angle1);
			  lz = -cos(angle1);
			  }*/
			  else{
				  pindx=indx;
				  g++;
				  gtheta=-90;
				  indx=3;
				  if(pindx==0)
				  {
					  intr=move_x;
					  move_x=move_z;
					  move_z=-intr;
				  }
				  else if(pindx==1)
				  {
					  move_x=-move_x;
					  move_z=-move_z;
				  }
				  else if(pindx==2)
				  {
					  intr=move_z;
					  move_z=move_x;
					  move_x=-intr;
				  }
				  //move_z+=0.2f;
				  move_z=move_z+0.2f*incr;	
			  }
			  //}
		}
	}
	else if (key == GLUT_KEY_RIGHT)
	{

		if(col1==0){
			col0=0;
			col1=0;
			col2=0;
			col3=0;
			//flagz=0;
			//flagx=1;
			if(tower%2==1)
			{
				angle += 0.01f;
				lx = sin(angle);
				lz = -cos(angle);
			}/*
			    else if(tower%2==0){	
			    if(person%2==1)
			    {
			    down=0;
			    angle1 += 0.03f;
			    lx = sin(angle1);
			    lz = -cos(angle1);
			    }*/
			    else{

				    pindx=indx;
				    g++;
				    gtheta=90;
				    indx=1;
				    if(pindx==0)
				    {
					    intr=move_z;
					    move_z=move_x;
					    move_x=-intr;
				    }
				    else if(pindx==2)
				    {
					    //printf("up to right..initial x..%f z..%f\n",xco,zco);
					    intr=move_x;
					    move_x=move_z;
					    move_z=-intr;
					    //printf("final x..%f z..%f\n",xco,zco);
				    }
				    else if(pindx==3)
				    {
					    move_z=-move_z;
					    move_x=-move_x;
				    }
				    move_z=move_z+0.2f*incr;	
				    //move_z+=0.2f;
			    }
			    //}
		}
	}
	else if (key == GLUT_KEY_UP)
	{
		if(col2==0){
			col0=0;
			col1=0;
			col2=0;
			col3=0;
			//flagx=0;
			//flagz=-1;
			//printf("flagz:%d\n");
			if(tower%2==1){
				cam_x += lx * fraction;
				cam_z += lz * fraction;}
			/*else if(tower%2==0){
			  if(person%2==1)
			  {
			  if(down>0){lx=-lx;lz=-lz;}
			  down=0;
			  move_x += lx * fraction;
			  move_z += lz * fraction;}

			 */
			  else{
				  printf("moving up\n");
				  pindx=indx;
				  g++;
				  gtheta=180;
				  indx=2;
				  if(pindx==0)
				  {
					  move_x=-move_x;
					  move_z=-move_z;
				  }
				  else if(pindx==1)
				  {
					  intr=move_z;
					  move_z=move_x;
					  move_x=-intr;
				  }
				  else if(pindx==3)
				  {
					  intr=move_x;
					  move_x=move_z;
					  move_z=-intr;
				  }
				  move_z=move_z+0.2f*incr;	
				  //		move_z+=0.2f;
			  }
			  //}
		}
	}
	else if (key == GLUT_KEY_DOWN)
	{ 
		if(col0==0){
			col0=0;
			col1=0;
			col2=0;
			col3=0;
			//flagx=0;
			//flagz=1;
			if(tower%2==1){
				cam_x -= lx * fraction;
				cam_z -= lz * fraction;}
			/*else if(tower%2==0){
			  if(person%2==1)
			  {
			  down++;
			  if(down==1){
			  lx=-lx;lz=-lz;
			  }

			  move_x += lx * fraction;
			  move_z += lz * fraction;
			  move_x -= lx * fraction;
			  move_z -= lz * fraction;

			  }*/
			  else
			  {
				  pindx=indx;
				  g++;
				  gtheta=0;
				  indx=0;
				  if(pindx==1)
				  {
					  intr=move_x;
					  move_x=move_z;
					  move_z=-intr;
				  }
				  else if(pindx==2)
				  {	
					  move_z=-move_z;
					  move_x=-move_x;
					  //zco=-zco;
					  //xco=-xco;
				  }
				  else if(pindx==3)
				  {
					  intr=move_x;
					  move_x=-move_z;
					  move_z=intr;
					  //intr=xco;
					  //xco=-zco;
					  //zco=intr;
				  }
				  move_z=move_z+0.2f*incr;	
				  //		move_z+=0.2f;
			  }
			  //}
		}
	}
}
}
}
/*
   void handleKeypress2(int key, int x, int y) {

   printf("%d\n",tower);
   float fraction = 0.1f;

   switch (key) {
   case GLUT_KEY_LEFT :
   {down=0;
   angle -= 0.01f;
   lx = sin(angle);
   lz = -cos(angle);
   break;}
   case GLUT_KEY_RIGHT :
   {down=0;
   angle += 0.01f;
   lx = sin(angle);
   lz = -cos(angle);
   break;}

   case GLUT_KEY_UP :
   {if(down==1){
   angle-=3.14159265;
   lx = sin(angle);
   lz = -cos(angle);
   angle+=3.14159265;
   }
   move_x += lx * fraction;
   move_z += lz * fraction;


   break;}
   case GLUT_KEY_DOWN :
   {
   angle-=3.14159265;
   lx = sin(angle);
   lz = -cos(angle);
   move_x -= lx * fraction;
   move_z -= lz * fraction;
   angle+=3.14159265;
   down=1;
   break;}
   }

//move_x += lx * fraction;
//move_z += lz * fraction;
}
 */
/*void handleMouseclick(int button, int state, int x, int y) {

  if (state == GLUT_DOWN)
  {
  if (button == GLUT_LEFT_BUTTON)
  theta += 15;
  else if (button == GLUT_RIGHT_BUTTON)
  theta -= 15;
  }
  }*/
