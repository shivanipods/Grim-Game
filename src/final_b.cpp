#define GL_GLEXT_PROTOTYPES
#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "glm.cpp"
#include "glm.h"
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp" 

/*******************************Variable declarations *******************************************

  Robot coordinate variables : 
  level increment : win =1 :756; win =0  means not cleared yet
 */










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
float rot=0.0f;
float chalo=0.0,chalo1=0.0f;
float aag=4;
int aagvar=0;
int naa=0;
int naa1=0;
int chalokaflag=0;
int chalokaflag1=0;
int imontile=0;
int gun=0;
int gun2 = 0;
char s[1];
char s1[1];
int press = 0;	
int windowWidth;
int windowHeight;
int w;
void drawRobot();
int h;
int level=1;
int shoot = 0;
int counter=0;
int counter1=0;
float _angle=0.0f;
/*
   float gunr =0.2f;
   float gund =0.2f;
   float gunu =0.2f;
   float gunl =0.2f;
   int ammo = 0;
 */
int notdraw=0;
int notdraw2=0;
int notdraw3=0;
int num;
int life=3;
int life2 = 3;
int t1=9,t2=14;
int horz,vert;
float changey=0.0;
int flag=0;
int gazeno=0;

int cube1=0;
int cube2=0;
int cube3=0;
float yRotated=0.0;
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
int levchanged=0;
int transtile=0;

//float theta = 0.0f;
int down=0;
int multiplay = 0;
int jump=0;
int down2=0;
int jump2=0;
int pindx=-1,indx=-1;
int pindx2=-1,indx2=-1;
int thirdp=0;
int tileview=0;
int block=0;
int roboup=0;
int incr=1;
int upview=0;
//float xco=0.0f,zco=0.0f;
float intr=0;
float intr2 =0;
//float theta = 0.0f; 
//float angle = 0.0f; 
Vector3D size,center;
Vector3D gunarr[6];
Vector3D gunarr2[6];
int gundir[6];
int gundir2[6];
GLMmodel *mod = NULL ;
GLMmodel *mod_ = NULL ;
GLMmodel *sphere = NULL;
GLMmodel *coins=NULL;
GLMmodel *mod2 =NULL;
GLMmodel *mod2_ =NULL;
GLMmodel *pmodel1 =NULL;
GLMmodel *pmodel2 =NULL;
int g=0,k=-1,tower=0,person=0,person2=0;
int g2=0,k2=-1;
int pause1=0;
//int h,v,numr=0;
int gtheta = 0;
int gtheta2 = 0;
float move_x=0.0f,move_y=0.0f,move_z=0.0f;
float move_x2=0.0f,move_y2=0.0f,move_z2=0.0f;
// angle of rotation for the camera direction
float angle=0.0;
float angle1=0.0;
float angle2 = 0.0;
float fraction = 0.1f;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;
float lx2 = 0.0f,lz2=-1.0f;//for the second robot
//float lx=0.0f,lz=-2.2f;
// XZ position of the camera
//float cam_x=1.5f,cam_y=-50.0f,cam_z=10.2f;
float cam_x=1.5f,cam_y=1.2f,cam_z=11.0f;//orig
//float cam_x=1.5f,cam_y=6.5f,cam_z=18.0f;
float cam_x2=1.5f,cam_y2=1.2f,cam_z2=7.0f;
float lookx,looky,lookz,facex,facey=0.0f,facez;
float lookx2,looky2,lookz2,facex2,facey2=0.0f,facez2;
float go_y=0.0f;
float go_y2=0.0f;
int fall=0,win=0;
int fall2=0,win2=0;
int col0=0,col1=0,col2=0,col3=0;
int col00=0,col11=0,col22=0,col33=0;//for second robot , to detect collision
Vector3D vtr;
AxisAlignedBoundingBox box1;
AxisAlignedBoundingBox box2;
int count1=0,count2=0;
// Function Declarations
void drawScene();
void drawLine();
void update(int value);
//void waterfall(int value);
void drawBox();
//void drawBall(float rad);
//void drawTriangle();
void moretiles(float a,float b, float c);
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
void drawCube(float a,float b,float c);

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
GLuint _textureId30;
GLuint _textureId31;
GLuint _textureId32;
GLuint _textureId33;
GLuint _textureId34;
GLuint _textureId35;
GLuint _textureId36;
GLuint _textureId37;
GLuint _textureId38;
GLuint _textureId39;
GLuint _textureId310;
GLuint _textureId311;
GLuint _textureId4;
GLuint _textureId5;
GLuint _textureId6;
GLuint _textureId70;
GLuint _textureId71;
GLuint _textureId72;
GLuint _textureId73;
GLuint _textureId74;
GLuint _textureId75;
GLuint _textureId76;
GLuint _textureId77;
GLuint _textureId78;
GLuint _textureId79;
GLuint _textureId710;
GLuint _textureId711;
GLuint _textureId8;
GLuint _textureId9;
int hrand[15],vrand[15];
int kr,m,ok;
int ok2;
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

	w = glutGet(GLUT_SCREEN_WIDTH);
	h = glutGet(GLUT_SCREEN_HEIGHT);
	windowWidth = w * 2 / 3;
	windowHeight = h * 2 / 3;
	//_scale = computeScale(STRS);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition((w - windowWidth) / 2, (h - windowHeight) / 2);

	glutCreateWindow("Grim Game");  // Setup the window
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
	//	glutTimerFunc(20, update, 0);


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
		/*	if(thirdp%2==1)
			{
			lookx=-(move_z-0.8f);
			}*/
		facex=lookx-2.0f;
		lookz=move_x;//+1.0f;
		facez=lookz;
	}
	if(indx==1)//right
		//if(flagx==1)
	{
		lookx=move_z;
		facex=lookx+1.0f;
		/*	if(thirdp%2==1)
			{
			lookx=(move_z-0.8f);
			facex=lookx+1.5f;
			}*/
		lookz=-move_x;//+1.0f;
		facez=lookz;
	}
	if(indx==0)//down
		//if(flagz==1)
	{
		lookx=move_x;
		lookz=move_z;
		/*	if(thirdp%2==1)
			{
			lookz=(move_z-0.6f);
			}
		 */	facex=lookx;
		facez=lookz+1.0f;
	}
	if(indx==2)//up
		//if(flagz==-1)
	{
		lookz=-move_z;
		/*	if(thirdp%2==1)
			{
			lookz=-(move_z-0.6f);
			}
		 */	lookx=-move_x;
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
			&& lookx+1.7 > -2-changey+(4.5-1-1)*0.45 && lookx+1.7 <-2-changey+(4.5/*horz tile from -2 */ -1)*0.45)
	{
		fall=1;
	}
	if(lookz+4.2<-1.7+(12/*vert tile from -1.7 */-1)*0.45 && lookz+4.2>-1.7+(12-1-1)*0.45 
			&& lookx+1.7 > -2-changey+(7.5-1-1)*0.45 && lookx+1.7 <-2-changey+(8/*horz tile from -2 */ -1)*0.45)
	{
		fall=1;
	}

	if(lookz+4.2<-1.7+changey+(1/*vert tile from -1.7 */-1)*0.45 && lookz+4.2>-1.7+changey+(1-1-1)*0.45 
			&& lookx+1.7 > -2+(6-1-1)*0.45 && lookx+1.7 <-2+(6/*horz tile from -2 */ -1)*0.45)
	{
		fall=1;
	}

	if(lookz+4.2<-1.7+(10-1)*0.45 && lookz+4.2>-1.7+(10-1-1)*0.45 
			&& lookx+1.7 > -2+(9-1-1)*0.45 && lookx+1.7 <-2+(9 -1)*0.45)
	{fall =1;}
	////////////////////////////////////////////////
	if(lookz2<-1.7+(vt/*vert tile from -1.7 */-1)*0.45 && lookz2>-1.7+(vt-1-1)*0.45 
			&& lookx2 > -2+(ht-1-1)*0.45 && lookx2 <-2+(ht/*horz tile from -2 */ -1)*0.45)
	{
		fall2=1;
	}
	if(lookz2<-1.7+(10/*vert tile from -1.7 */-1)*0.45 && lookz2>-1.7+(10-1-1)*0.45 
			&& lookx2 > -2-changey+(4.5-1-1)*0.45 && lookx2 <-2-changey+(4.5/*horz tile from -2 */ -1)*0.45)
	{
		fall2=1;
	}
	if(lookz2<-1.7+(12/*vert tile from -1.7 */-1)*0.45 && lookz2>-1.7+(12-1-1)*0.45 
			&& lookx2 > -2-changey+(7.5-1-1)*0.45 && lookx2 <-2-changey+(8/*horz tile from -2 */ -1)*0.45)
	{
		fall2=1;
	}

	if(lookz2<-1.7+changey+(1/*vert tile from -1.7 */-1)*0.45 && lookz2>-1.7+changey+(1-1-1)*0.45 
			&& lookx2 > -2+(6-1-1)*0.45 && lookx2 <-2+(6/*horz tile from -2 */ -1)*0.45)
	{
		fall2=1;
	}

	if(lookz2<-1.7+(10-1)*0.45 && lookz2>-1.7+(10-1-1)*0.45 
			&& lookx2 > -2+(9-1-1)*0.45 && lookx2 <-2+(9 -1)*0.45)
	{fall2 =1;}



}

void drawGun()
{
	glPushMatrix();
	if(gun == 1)
	{
		drawLine();
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.2,-0.1,3);
	//glTranslatef(lookx,looky,lookz);
	glScalef(0.2,0.2,0.2);
	if(!sphere)
	{
		strcpy(temp,"Flintlock_pistol.obj");
		sphere = glmReadOBJ(temp);
		if(!sphere) exit(0);
		glmUnitize(sphere);
		glmFacetNormals(sphere);
		glmVertexNormals(sphere, 90.0);
	}
	if(lookz+4.2<-1.7+(11/*vert tile from -1.7 */-1)*0.45 && lookz+4.2>-1.7+(11-1-1)*0.45 
			&& lookx+1.7 > -2+(5-1-1)*0.45 && lookx+1.7 <-2+(5/*horz tile from -2 */ -1)*0.45)
	{
		gun=1;
		//level=2;
		//	printf("lookx: %f %f %f\n",lookx,looky,lookz);
	}

	if(gun==0)
		glmDraw(sphere, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
	glPopMatrix();
}
void moretiles(float a,float b, float c)
{
	float l=0.2,h=0.05,br=0.2;

	glEnable(GL_COLOR_MATERIAL);    // Enable coloring
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glColor3f(1,1,1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTranslatef(a,b,c);
	//Front-white

	glBegin(GL_POLYGON);
	glColor3f(   1.0,  1.0, 1.0 );
	glTexCoord2f(0.0f, 0.0f);
	//if(block==1){glVertex3f(-l,0,b);}else
	glVertex3f( -l, -h, br );

	glTexCoord2f(1.0f, 0.0f);
	//if(block==1){glVertex3f(l,0,b);}else
	glVertex3f(  l, -h, br );

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(  l,  h, br );

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f( -l,  h, br );
	glEnd();


	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(   1.0,  1.0, 1.0 );
	//glColor3f(   1.0,  1.0, 1.0 );
	//glColor3f(  1.0,  0.0,  1.0 );
	glTexCoord2f(0.0f, 0.0f);
	//if(block==1){glVertex3f(l,0,-b);}else
	glVertex3f( l, -h, -br );
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f( l,  h, -br );
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f( l,  h,  br );
	glTexCoord2f(0.0f, 1.0f);
	//if(block==1){glVertex3f(l,0,b);}else
	glVertex3f( l, -h,  br );
	glEnd();

	// Green side - LEFT
	glBegin(GL_POLYGON);
	glColor3f(   1.0,  1.0, 1.0 );
	//glColor3f(   0.0,  0.0, 0.0 );
	//glColor3f(   1.0,  0.0,  0.0 );
	glTexCoord2f(0.0f, 0.0f);
	//if(block==1){glVertex3f(-l,0,b);}else
	glVertex3f( -l, -h,  br );
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f( -l,  h,  br );
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f( -l,  h, -br );
	glTexCoord2f(0.0f, 1.0f);
	//if(block==1){glVertex3f(-l,0,-b);}else
	glVertex3f( -l, -h, -br );
	glEnd();

	// Blue side - TOP
	glBegin(GL_POLYGON);
	glColor3f(   1.0,  1.0, 1.0 );
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(  l,  h,  br );
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(  l,  h, -br );
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f( -l,  h, -br );
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f( -l,  h,  br);
	glEnd();

	//Back
	glBegin(GL_POLYGON);
	glColor3f(   1.0,  1.0, 1.0 );
	//glColor3f(   1.0,  1.0,  0.0 );
	glTexCoord2f(0.0f, 0.0f);
	//if(block==1){glVertex3f(-l,0,-b);}else
	glVertex3f( -l, -h, -br );
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f( -l,  h, -br );
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(  l,  h, -br );
	glTexCoord2f(0.0f, 1.0f);
	//	if(block==1){glVertex3f(l,0,-b);}else
	glVertex3f(  l, -h, -br );
	glEnd();


	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(   1.0,  1.0,  1.0 );
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(  l, h, -br );
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(  l, h,  br );
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f( -l, h,  br );
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f( -l, h, -br );
	glEnd();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);

	glEnable(GL_LIGHTING);
}



void drawCube(float a,float b,float c)
{
	glPushMatrix();
	glTranslatef(a,b,c);
	glRotatef(yRotated,0.0,1.0,0.0);
	glBegin(GL_QUADS);        // Draw The Cube Using quads
	//      glColor3f(0.0f,1.0f,0.0f);    // Color Blue
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Top)
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Top)
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f( 1.0f, 1.0f, 1.0f);
	//glColor3f(1.0f,0.5f,0.0f);    // Color Orange
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f( 1.0f,-1.0f, 1.0f);    // Top Right Of The Quad (Bottom)
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f,-1.0f, 1.0f);    // Top Left Of The Quad (Bottom)
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Bottom)
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Bottom)
	//glColor3f(1.0f,0.0f,0.0f);    // Color Red    
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Front)
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Front)
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Front)
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Front)
	//glColor3f(1.0f,1.0f,0.0f);    // Color Yellow
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f( 1.0f,-1.0f,-1.0f);    // Top Right Of The Quad (Back)
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);    // Top Left Of The Quad (Back)
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f,-1.0f);    // Bottom Left Of The Quad (Back)
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f( 1.0f, 1.0f,-1.0f);    // Bottom Right Of The Quad (Back)
	//glColor3f(0.0f,0.0f,1.0f);    // Color Blue
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Left)
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Left)
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Left)
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Left)
	//glColor3f(1.0f,0.0f,1.0f);    // Color Violet
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Right)
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Right)
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Right)
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Right)
	glEnd();

	glPopMatrix();
} 

// Function to draw objects on the screen
void drawScene() {

	printf("see...%f %f %f\n",lookx,looky,lookz);
	printf("MULTIPLAY = %d---------------------\n",multiplay);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	if(multiplay == 1)
	{
		glLoadIdentity();
		glViewport(0,0,w/2,h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (float)w / (float)h, 0.1f, 200.0f);
		glMatrixMode(GL_MODELVIEW);
		if(level==1)
			gluLookAt(	cam_x2, cam_y2, cam_z2,cam_x2+lx,cam_y2-0.4f,  cam_z2+lz,0.0f, 1.0f,  0.0f);
		else if(level==2)
		{

			gluLookAt(	cam_x2, cam_y2, cam_z2,
					cam_x2+lx,cam_y2,  cam_z2+lz,			
					0.0f, 1.0f,  0.0f);
		}
		else if(level==3)
		{

			gluLookAt(	cam_x2, cam_y2, cam_z2,
					cam_x2+lx,cam_y2,  cam_z2+lz,			
					0.0f, 1.0f,  0.0f);
		}

		if(level==1)
			drawBox();

		view();
		if(level==2)
		{
			glPushMatrix();
			glTranslatef(0,-55,-10);

			glDisable(GL_LIGHTING);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, _textureId5);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

			//base
			glPushMatrix();
			//glTranslatef(0,0,-5);
			glBegin(GL_POLYGON);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f( -40, -1, -2 );
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(  40, -1, -2 );
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(  40,  -1, 20 );
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f( -40, -1, 20 );
			glEnd();
			glPopMatrix();


			glBindTexture(GL_TEXTURE_2D, _textureId5);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			//front wall
			glPushMatrix();
			glTranslatef(0,-6,-35);
			glScalef(2.5,2.5,2.5);
			glBegin(GL_POLYGON);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f( -48, -10, -40 );
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f( 50, -10, -40 );
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(  50, 40, -40 );
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(  -48,  40, -40 );
			glEnd();
			glPopMatrix();

			glBindTexture(GL_TEXTURE_2D, _textureId6);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			if(gun==1)
			{
				if(gunarr[shoot].x >10 &&
						gunarr[shoot].z<-5 && gunarr[shoot].z >-25
				  )
					cube1=1;
			}
			if(cube1==0){
				drawCube(10,0,0);}
			else if(cube1==1) 
			{
				if(lookx<14 && lookx > 11 && lookz < -10 && lookz> -20)
				{ notdraw=1;}
				if(notdraw!=1)
				{
					glDisable(GL_TEXTURE_2D);
					glPushMatrix();
					glTranslatef(10,0,0);
					glColor3f(0.8,0.498,0.196);
					glScalef(0.5,0.5,0.5);
					glRotatef(_angle,0,1,1);

					glmDraw(coins, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
					glPopMatrix();
					glEnable(GL_TEXTURE_2D);
				}

			}
			if(gun==1)
			{
				if(  gunarr[shoot].z<-30 && gunarr[shoot].z >-55
						&& gunarr[shoot].x<-12 
				  )
				{	cube2=1;
					printf("gunarr................................%f %f %f\n",gunarr[shoot].x,gunarr[shoot].y,gunarr[shoot].z);
				}
			}


			if(cube2==0)
				drawCube(-7,1,-20);
			else if(cube2==1) 
			{
				if(lookx<-10 && lookx > -20 && lookz < -40 && lookz> -60)
				{ notdraw2=1;}
				if(notdraw2!=1)
				{

					glDisable(GL_TEXTURE_2D);
					glPushMatrix();
					glTranslatef(-7,1,-20);
					glColor3f(1,0,0);
					glScalef(0.5,0.5,0.5);
					glRotatef(_angle,1,0,0);

					glmDraw(coins, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
					glPopMatrix();
					glEnable(GL_TEXTURE_2D);
				}

			}

			if(gun==1)
			{
				if(  gunarr[shoot].z<-70 && gunarr[shoot].z >-90
						&& gunarr[shoot].x>30
				  )
				{	cube3=1;
					printf("gunarr................................%f %f %f\n",gunarr[shoot].x,gunarr[shoot].y,gunarr[shoot].z);
				}
			}
			if(cube3==0)
				drawCube(25,0,-50);
			else if(cube3==1) 
			{
				if(lookx<44 && lookx > 30 && lookz < -85 && lookz> -110)
				{ notdraw3=1;}
				if(notdraw3!=1)
				{

					glDisable(GL_TEXTURE_2D);
					glPushMatrix();
					glTranslatef(25,0,-50);
					glColor3f(1,0,0);

					glScalef(0.5,0.5,0.5);
					glRotatef(_angle,1,0,0);

					glmDraw(coins, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
					glPopMatrix();
					glEnable(GL_TEXTURE_2D);
				}

			}



			glPopMatrix();
		}
		view();
		if(level==3)
		{
	glDisable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);

//		cam_x=1.5f,cam_y=50.0f,cam_z=10.0f;
//		cam_x2=1.5f,cam_y2=50.0f,cam_z2=10.0f;
		incr=3;

//		gluLookAt(	cam_x, cam_y, cam_z,
//				cam_x+lx,cam_y,  cam_z+lz,			
//				0.0f, 1.0f,  0.0f);
		glTranslatef(0,45,-10);
		glBindTexture(GL_TEXTURE_2D, _textureId8);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		//base
		glPushMatrix();
		//glTranslatef(0,0,-5);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f( -45, -20, -40 );
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f( 48, -20, -40 );
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(  48, 30, -40 );
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(  -44,  30, -40 );
		glEnd();
		glPopMatrix();
//		drawRobot();

		glEnable(GL_TEXTURE_2D);
		glPushMatrix();
		//glTranslatef(0,0,-20);
		if(counter1 == 0)
			glBindTexture(GL_TEXTURE_2D, _textureId70);
		if(counter1 == 1)
			glBindTexture(GL_TEXTURE_2D, _textureId71);
		if(counter1 == 2)
			glBindTexture(GL_TEXTURE_2D, _textureId72);
		if(counter1 == 3)
			glBindTexture(GL_TEXTURE_2D, _textureId73);
		if(counter1 == 4)
			glBindTexture(GL_TEXTURE_2D, _textureId74);
		if(counter1 == 5)
			glBindTexture(GL_TEXTURE_2D, _textureId75);
		if(counter1 == 6)
			glBindTexture(GL_TEXTURE_2D, _textureId76);
		if(counter1 == 7)
			glBindTexture(GL_TEXTURE_2D, _textureId77);
		if(counter1 == 8)
			glBindTexture(GL_TEXTURE_2D, _textureId78);
		if(counter1 == 9)
			glBindTexture(GL_TEXTURE_2D, _textureId79);
		if(counter1 == 10)
			glBindTexture(GL_TEXTURE_2D, _textureId710);
		if(counter1 == 11)
			glBindTexture(GL_TEXTURE_2D, _textureId711);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

/*glPushMatrix();
glTranslatef(10,4,2);
glRotatef(90,1,0,0);
glScalef(2,1,1);
//glRotatef(180,0,0,1);
//glRotatef(_angle,0,1,0);
		glBegin(GL_POLYGON);        // Draw The Cube Using quads
	//      glColor3f(0.0f,1.0f,0.0f);    // Color Blue
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Top)
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Top)
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f( 1.0f, 1.0f, 1.0f);
glEnd();

glPopMatrix();*/


		glPushMatrix();
glTranslatef(10,4,2);
glRotatef(90,1,0,0);
glScalef(aag,1,1);
//glRotatef(-20,0,0,1);
		glBegin(GL_POLYGON);        // Draw The Cube Using quads
	//      glColor3f(0.0f,1.0f,0.0f);    // Color Blue
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Top)
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Top)
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f( 1.0f, 1.0f, 1.0f);
glEnd();

glPopMatrix();

glPushMatrix();
glTranslatef(-10,4,-2);
glRotatef(90,1,0,0);
glRotatef(180,0,0,1);
glScalef(aag,1,1);
//glRotatef(-20,0,0,1);
		glBegin(GL_POLYGON);        // Draw The Cube Using quads
	//      glColor3f(0.0f,1.0f,0.0f);    // Color Blue
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Top)
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Top)
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f( 1.0f, 1.0f, 1.0f);
glEnd();

glPopMatrix();


glPushMatrix();
glTranslatef(-10,4,5);
glRotatef(90,1,0,0);
glRotatef(180,0,0,1);
glScalef(aag,1,1);
//glRotatef(-20,0,0,1);
		glBegin(GL_POLYGON);        // Draw The Cube Using quads
	//      glColor3f(0.0f,1.0f,0.0f);    // Color Blue
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Top)
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Top)
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f( 1.0f, 1.0f, 1.0f);
glEnd();

glPopMatrix();


glPopMatrix();
		}
		drawRobot();

		glLoadIdentity();
		glViewport(w/2, 0, w/2, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (float)w / (float)h, 0.1f, 200.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		//drawBox();
	}
	if(multiplay == 0)
	{
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (float)w / (float)h, 0.1f, 200.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//drawBox();

	}

	if(!coins)
	{
		coins = glmReadOBJ("TyveKrone.obj");
		if(!coins) exit(0);
		glmUnitize(coins);
		glmFacetNormals(coins);
		glmVertexNormals(coins,90.0);
	}

	glColor3f(1.0f, 1.0f, 1.0f);
	printf("global x: %f y: %f z: %f\n",lookx,looky,lookz);
	if(level==2 && levchanged==0) ///make it 1
	{
	//	glDisable(GL_LIGHTING);

		cam_x=1.5f,cam_y=-50.0f,cam_z=15.0f;
		cam_x2=1.5f,cam_y2=-50.0f,cam_z2=15.0f;
		incr=3;
		view();
		glTranslatef(0,-55,-10);
		if(thirdp%2==0)
		{
			gluLookAt(	cam_x, cam_y, cam_z,
					cam_x+lx,cam_y,  cam_z+lz,			
					0.0f, 1.0f,  0.0f);
		}
		else
		{
			if(indx==3)

			{
				//lookx=-(move_z-0.8f);
				gluLookAt(	lookx+1+0.8, looky-0.1f , lookz+9.2,
						facex+1,facey,  facez+9.2,
						0.0f, 1.0f,  0.0f);
			}
			else if(indx==1)
			{
				//lookx=(move_z-0.8f);
				//facex=lookx+1.5f;
				gluLookAt(	lookx+1-0.8, looky-0.1f , lookz+9.2,
						facex+1+0.5,facey,  facez+9.2,
						0.0f, 1.0f,  0.0f);

			}
			else if(indx==0)
			{

				gluLookAt(	lookx+1, looky-0.1f , lookz+9.2-0.6,
						facex+1,facey,  facez+9.2,
						0.0f, 1.0f,  0.0f);

			}
			else if(indx==2)
			{

				//		gluLookAt(	lookx+1.7, looky-0.1f+5.0f , lookz+4.2+0.6+20.0f,
				//				facex+1.7,facey,  facez+4.2,
				//				0.0f, 1.0f,  0.0f);
				gluLookAt( lookx+1,looky, lookz+9.2+40.0f,
						lookx+1,looky-3.0f,lookz+9.2,
						0,1,0);

			}





		}


		//glEnable(GL_COLOR_MATERIAL);    // Enable coloring

		glDisable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureId5);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		//base
		glPushMatrix();
		//glTranslatef(0,0,-5);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f( -40, -1, -2 );
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(  40, -1, -2 );
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(  40,  -1, 20 );
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f( -40, -1, 20 );

		glEnd();
		glPopMatrix();

		glBindTexture(GL_TEXTURE_2D, _textureId5);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		//front wall
		glPushMatrix();
		glTranslatef(0,-6,-35);
		glScalef(2.5,2.5,2.5);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f( -48, -10, -40 );
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f( 50, -10, -40 );
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(  50, 40, -40 );
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(  -48,  40, -40 );
		glEnd();
		glPopMatrix();

		glBindTexture(GL_TEXTURE_2D, _textureId6);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		if(gun==1)
		{
			if(gunarr[shoot].x >10 &&
					gunarr[shoot].z<-5 && gunarr[shoot].z >-25
			  )
				cube1=1;
		}
		if(cube1==0){
			drawCube(10,0,0);}
		else if(cube1==1) 
		{
			if(lookx<14 && lookx > 11 && lookz < -10 && lookz> -20)
			{ notdraw=1;}
			if(notdraw!=1)
			{
				glDisable(GL_TEXTURE_2D);
				glPushMatrix();
				glTranslatef(10,0,0);
				glColor3f(0.8,0.498,0.196);
				glScalef(0.5,0.5,0.5);
				glRotatef(_angle,0,1,1);

				glmDraw(coins, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
				glPopMatrix();
				glEnable(GL_TEXTURE_2D);
			}

		}
		if(gun==1)
		{
			if(  gunarr[shoot].z<-30 && gunarr[shoot].z >-55
					&& gunarr[shoot].x<-12 
			  )
			{	cube2=1;
				printf("gunarr................................%f %f %f\n",gunarr[shoot].x,gunarr[shoot].y,gunarr[shoot].z);
			}
		}


		if(cube2==0)
			drawCube(-7,1,-20);
		else if(cube2==1) 
		{
			if(lookx<-10 && lookx > -20 && lookz < -40 && lookz> -60)
			{ notdraw2=1;}
			if(notdraw2!=1)
			{

				glDisable(GL_TEXTURE_2D);
				glPushMatrix();
				glTranslatef(-7,1,-20);
				glColor3f(1,0,0);
				glScalef(0.5,0.5,0.5);
				glRotatef(_angle,1,0,0);

				glmDraw(coins, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
				glPopMatrix();
				glEnable(GL_TEXTURE_2D);
			}

		}

		if(gun==1)
		{
			if(  gunarr[shoot].z<-70 && gunarr[shoot].z >-90
					&& gunarr[shoot].x>30
			  )
			{	cube3=1;
				printf("gunarr................................%f %f %f\n",gunarr[shoot].x,gunarr[shoot].y,gunarr[shoot].z);
			}
		}
		if(cube3==0)
			drawCube(25,0,-50);
		else if(cube3==1) 
		{
			if(lookx<44 && lookx > 30 && lookz < -85 && lookz> -110)
			{ notdraw3=1;}
			if(notdraw3!=1)
			{

				glDisable(GL_TEXTURE_2D);
				glPushMatrix();
				glTranslatef(25,0,-50);
				glColor3f(1,0,0);

				glScalef(0.5,0.5,0.5);
				glRotatef(_angle,1,0,0);

				glmDraw(coins, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
				glPopMatrix();
				glEnable(GL_TEXTURE_2D);
			}

		}

		drawRobot();
	}
	if(notdraw==1 && notdraw2==1 && notdraw3==1)
	{
		level=3;
	
	}
//if(teleport==1)
//	{

	if(level==3)
	{
		naa1=1;
		glDisable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);

		cam_x=1.5f,cam_y=50.0f,cam_z=10.0f;
		cam_x2=1.5f,cam_y2=50.0f,cam_z2=10.0f;
		incr=3;

		gluLookAt(	cam_x, cam_y, cam_z,
				cam_x+lx,cam_y,  cam_z+lz,			
				0.0f, 1.0f,  0.0f);
		view();
		glTranslatef(0,45,-10);
		glBindTexture(GL_TEXTURE_2D, _textureId8);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		//base
		glPushMatrix();
		//glTranslatef(0,0,-5);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f( -45, -20, -40 );
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f( 48, -20, -40 );
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(  48, 30, -40 );
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(  -44,  30, -40 );
		glEnd();
		glPopMatrix();
		glEnable(GL_TEXTURE_2D);
		glPushMatrix();
		//glTranslatef(0,0,-20);
		if(counter1 == 0)
			glBindTexture(GL_TEXTURE_2D, _textureId70);
		if(counter1 == 1)
			glBindTexture(GL_TEXTURE_2D, _textureId71);
		if(counter1 == 2)
			glBindTexture(GL_TEXTURE_2D, _textureId72);
		if(counter1 == 3)
			glBindTexture(GL_TEXTURE_2D, _textureId73);
		if(counter1 == 4)
			glBindTexture(GL_TEXTURE_2D, _textureId74);
		if(counter1 == 5)
			glBindTexture(GL_TEXTURE_2D, _textureId75);
		if(counter1 == 6)
			glBindTexture(GL_TEXTURE_2D, _textureId76);
		if(counter1 == 7)
			glBindTexture(GL_TEXTURE_2D, _textureId77);
		if(counter1 == 8)
			glBindTexture(GL_TEXTURE_2D, _textureId78);
		if(counter1 == 9)
			glBindTexture(GL_TEXTURE_2D, _textureId79);
		if(counter1 == 10)
			glBindTexture(GL_TEXTURE_2D, _textureId710);
		if(counter1 == 11)
			glBindTexture(GL_TEXTURE_2D, _textureId711);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

glPushMatrix();
glTranslatef(10,4,2);
glRotatef(90,1,0,0);
glScalef(aag,1,1);
//glRotatef(-20,0,0,1);
		glBegin(GL_POLYGON);        // Draw The Cube Using quads
	//      glColor3f(0.0f,1.0f,0.0f);    // Color Blue
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Top)
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Top)
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f( 1.0f, 1.0f, 1.0f);
glEnd();

glPopMatrix();

glPushMatrix();
glTranslatef(-10,4,-2);
glRotatef(90,1,0,0);
glRotatef(180,0,0,1);
glScalef(aag,1,1);
//glRotatef(-20,0,0,1);
		glBegin(GL_POLYGON);        // Draw The Cube Using quads
	//      glColor3f(0.0f,1.0f,0.0f);    // Color Blue
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Top)
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Top)
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f( 1.0f, 1.0f, 1.0f);
glEnd();

glPopMatrix();


glPushMatrix();
glTranslatef(-10,4,5);
glRotatef(90,1,0,0);
glRotatef(180,0,0,1);
glScalef(aag,1,1);
//glRotatef(-20,0,0,1);
		glBegin(GL_POLYGON);        // Draw The Cube Using quads
	//      glColor3f(0.0f,1.0f,0.0f);    // Color Blue
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Top)
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Top)
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f( 1.0f, 1.0f, 1.0f);
glEnd();

glPopMatrix();

glPopMatrix();
	
if(level==3 && lookx < 10 && lookx >-10 && lookz < -30 && lookz > -40)
		{
	glPushMatrix();
		//glEnable(GL_COLOR_MATERIAL);    // Enable coloring
		glColor3f(1,0,0);

		glScalef(1, 1, 1);
		glTranslatef(vtr.x, vtr.y+10, vtr.z);
		//if(win==1 && count1==1 && count2==1){ 
		glColor3f(1,0,0);
		t3dDraw3D("You win !! :D ",0,0,0.2f);
		glPopMatrix();

		}

		drawRobot();


	}
	/*
	   if(level==2 && levchanged==0) ///make it 1
	   {
	   cam_x=1.5f,cam_y=-50.0f,cam_z=10.2f;
	   incr=3;
	   view();
	   gluLookAt(	cam_x, cam_y, cam_z,
	   cam_x+lx,cam_y,  cam_z+lz,			
	   0.0f, 1.0f,  0.0f);
	   glTranslatef(0,-55,-10);
	// glRotatef(-20,0,1,0);

	//glEnable(GL_COLOR_MATERIAL);    // Enable coloring

	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//front wall
	glPushMatrix();
	glBegin(GL_POLYGON);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f( -45, -20, -40 );
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f( 48, -20, -40 );
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(  48, 30, -40 );
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(  -44,  30, -40 );

	glEnd();
	glPopMatrix();

	}
	 */

	//drawBox();	
	/*
	   glPushMatrix();

	   glEnable(GL_COLOR_MATERIAL);    // Enable coloring
	   glColor3f(1,0,0);
	   glTranslatef(move_x,move_y,move_z);
	   if(g%3==0)
	   {	if(pmodel1){
	   glmDelete(pmodel1);
	   pmodel1=NULL;}

	   if (!mod) 
	   {   	
	   if(gun==0)
	   strcpy(temp, "grim_stand_f.obj");
	   else if(gun==1)
	   strcpy(temp, "stand_gun.obj");
	//		                strcpy(temp, "right_leg.obj");
	//	            if(count % 3 == 2)
	//			                strcpy(temp,"left_f.obj");
	mod = glmReadOBJ(temp);     
	if (!mod) exit(0);
	glmUnitize(mod);
	glmFacetNormals(mod);     
	glmVertexNormals(mod, 90.0);

	}

	//	ok=0;
	//	if(person%2==1 && indx==0)
	//	{ok=1;}
	//	if(ok!=1){
	//glScalef(0.5,0.5,0.5);
	//		glScalef(0.4,0.4,0.4);
	glScalef(2,2,2);
	glmDraw(mod, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
	//glmDraw(mod, GLM_SMOOTH | GLM_MATERIAL);
	//	}	//glPopMatrix();
	}
	else if(g%3==1)
	{    
	//glPushMatrix();

	if(mod)
	{glmDelete(mod);
	mod=NULL;}
	if(!mod2 )
	{
	if(gun==0)
	strcpy(temp, "right_leg.obj");
	else if(gun==1)
	strcpy(temp, "right_gun_f.obj");
	//	strcpy(temp,"orig1.obj");
	mod2 = glmReadOBJ(temp);
	//mod2 = glmReadOBJ("orig1.obj");
	if(!mod2) exit(0);
	glmUnitize(mod2);
	glmFacetNormals(mod2);
	glmVertexNormals(mod2, 90.0);
	//glmDimensions(mod2, dim);
	//printf("%f %f %f\n",dim[0],dim[1],dim[2]);
	}
	//	ok=0;
	//	if(person%2==1 && indx==0)
	//	{ok=1;}
	//	if(ok!=1){
	//		glScalef(0.4,0.4,0.4);
	glScalef(2,2,2);
	glmDraw(mod2, GLM_SMOOTH | GLM_MATERIAL);
	//	}
	}
	else if(g%3==2)
	{
		if(mod2){
			glmDelete(mod2);
			mod2=NULL;}
		if (!pmodel1) 
		{   	//strcpy(temp, "grim_stand_f.obj");
			//		                strcpy(temp, "right_leg.obj");
			//	            if(count % 3 == 2)
			if(gun==0)
				strcpy(temp,"left_f.obj");
			else if(gun==1)
				strcpy(temp,"left_gun.obj");
			pmodel1 = glmReadOBJ(temp);     
			if (!pmodel1) exit(0);
			glmUnitize(pmodel1);
			glmFacetNormals(pmodel1);     
			glmVertexNormals(pmodel1, 90.0);

		}

		//	ok=0;
		//	if(person%2==1 && indx==0)
		//	{ok=1;}
		//	if(ok!=1){
		//		glScalef(0.4,0.4,0.4);
		glScalef(2,2,2);
		glmDraw(pmodel1, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
		//glmDraw(mod, GLM_SMOOTH | GLM_MATERIAL);
		//	}	//glPopMatrix();
	}
	glPopMatrix();
	//	glPopMatrix();


	*/

		view();

	if(level==1)
	{
		if(upview%2==0 && person%2==0 && thirdp%2==0 && tileview%2==0 && gazeno%2==0)
		{	gluLookAt(	cam_x, cam_y, cam_z,
				cam_x+lx,cam_y-0.4f,  cam_z+lz,			
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

		if(person%2==1 ){
			//	if(thirdp%2==1){looky=1.0f;}
			if(fall==1){looky=go_y;facey=looky;}
			gluLookAt(	lookx+1.7, looky-0.1f , lookz+4.2,
					facex+1.7,facey,  facez+4.2,
					0.0f, 1.0f,  0.0f);
			//printf("movex:%f movez:%f\n",move_x,move_z);
			//printf("lookx:%f lookz:%f\n",lookx+1.7,lookz+3.2);
			//printf("facex:%f facez:%f\n",facex+1.7,facez+3.2);
		}	
		else
			if( thirdp%2==1){
				if(thirdp%2==1){looky=1.0f;}//looky=1.0f;
				if(fall==1){looky=go_y;facey=looky;}
				if(naa1==1)
				{

					if(indx==3)
					{
						//lookx=-(move_z-0.8f);
						gluLookAt(	lookx+1.7+0.8, looky-0.1f , lookz+4.2,
								facex+1.7,facey,  facez+4.2,
								0.0f, 1.0f,  0.0f);
					}
					else if(indx==1)
					{
						//lookx=(move_z-0.8f);
						//facex=lookx+1.5f;
						gluLookAt(	lookx+1.7-0.8, looky-0.1f , lookz+4.2,
								facex+1.7+0.5,facey,  facez+4.2,
								0.0f, 1.0f,  0.0f);

					}
					else if(indx==0)
					{

						gluLookAt(	lookx+1.7, looky-0.1f , lookz+4.2-0.6,
								facex+1.7,facey,  facez+4.2,
								0.0f, 1.0f,  0.0f);

					}
					else if(indx==2)
					{

						gluLookAt(	lookx+1.7, looky-0.1f , lookz+4.2+0.6,
								facex+1.7,facey,  facez+4.2,
								0.0f, 1.0f,  0.0f);

					}


				}
				else
				{
					if(indx==3)
					{
						//lookx=-(move_z-0.8f);
						gluLookAt(	lookx+1.7+0.8, looky-0.1f , lookz+4.2,
								facex+1.7,facey,  facez+4.2,
								0.0f, 1.0f,  0.0f);
					}
					else if(indx==1)
					{
						//lookx=(move_z-0.8f);
						//facex=lookx+1.5f;
						gluLookAt(	lookx+1-0.8, looky-0.1f , lookz+9.2,
								facex+1+0.5,facey,  facez+9.2,
								0.0f, 1.0f,  0.0f);

					}
					else if(indx==0)
					{

						gluLookAt(	lookx+1, looky-0.1f , lookz+9.2-0.6,
								facex+1,facey,  facez+9.2,
								0.0f, 1.0f,  0.0f);

					}
					else if(indx==2)
					{

						gluLookAt(	lookx+1, looky-0.1f , lookz+9.2+0.6,
								facex+1,facey,  facez+9.2,
								0.0f, 1.0f,  0.0f);

					}
				}
				//printf("movex:%f movez:%f\n",move_x,move_z);
				//printf("lookx:%f lookz:%f\n",lookx+1.7,lookz+3.2);
				//printf("facex:%f facez:%f\n",facex+1.7,facez+3.2);
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
		{if(count1==1 && count2==1)win=1;level=2;}

		if(lookz+4.2<-1.7+(13/*vert tile from -1.7 */-1)*0.45 && lookz+4.2>-1.7+(13-1-1)*0.45 
				&& lookx+1.7 > -2+(4-1-1)*0.45 && lookx+1.7 <-2+(4/*horz tile from -2 */ -1)*0.45)
		{count1=1;}
		if(lookz+4.2<-1.7+(7/*vert tile from -1.7 */-1)*0.45 && lookz+4.2>-1.7+(7-1-1)*0.45 
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
		//checkvoid(3,5);
		checkvoid(2,10);
		//checkvoid(6,4);
		checkvoid(3,14);
		checkvoid(4,14);
		checkvoid(5,14);


		checkvoid(1,13);
		checkvoid(1,12);
		checkvoid(1,6);
		//checkvoid(3,2);
		//checkvoid(3,3);
		//checkvoid(1,4);
		//checkvoid(4,1);
		//checkvoid(1,2);
		//checkvoid(6,6);
		//checkvoid(6,7);
		checkvoid(7,7);
		checkvoid(7,8);
		checkvoid(4,7);
		//checkvoid(5,8);
		//checkvoid(6,9);
		checkvoid(9,10);
		//checkvoid(5,5);
		checkvoid(6,2);
		checkvoid(9,1);
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
		drawRobot();
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
	}
	drawGun();
	//	printf("g:.................%d\n",g);
	/*
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
	 */
	//glPopMatrix();
	//printf("2: %f %f %f %f %f %f\n",box2.min.x+move_x,box2.min.y,box2.min.z+move_z,box2.max.x+move_x,box2.max.y,box2.max.z+move_z);
	// printf("2: %f %f %f %f %f %f\n",box2.min.x,box2.min.y,box2.min.z,box2.max.x,box2.max.y,box2.max.z);
	// printf("%f %f\n",move_x,move_z);
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
	num=count1+count2+notdraw2+notdraw3+notdraw;
	s[0]=(char)num+48;
	s[1]='\0';
	//printf(".........................%s\n",s);
	//itoa(count1+count2,buffer,10);
	//glColor3f(0.3f, 1.0f, 0.3f);

	//if(level==1)
	//{
	char score[10]="Score:";
	strcat(score,s);
	glPushMatrix();
	//glEnable(GL_COLOR_MATERIAL);    // Enable coloring
	//glColor3f(1,0,0);
	if(level==1){
		glScalef(0.2, 0.2, 0.2);
		glTranslatef(-1, 1, -1);
	}
	else{
		glScalef(1.2, 1.2, 1.2);
		glTranslatef(-10, 10, -1);
	}
	t3dDraw3D(score,1,0,0.2f);
	glTranslatef(0, 1, 0);
	s1[0]=(char)life+48;
	s1[1]='\0';
	char lyf[10]="Life:";
	strcat(lyf,s1);
	t3dDraw3D(lyf,1,0,0.2f);
	glPopMatrix();

	if(fall2==1 && win2==0){
		if(life2==1){
			life2--;
		}
		if(life2==0)
		{
			t3dDraw3D(str,0,0,0.2f);
		}


		if(life2>1){
			fall2=0;
			go_y2=0;
			move_x2=0.0f;move_y2=0.0f;move_z2=0.0f;

			down2=0;
			jump2=0;
			pindx2=-1,indx2=-1;
			thirdp=0;
			tileview=0;
			block=0;
			roboup=0;
			incr=1;
			upview=0;
			flag=0;
			gazeno=0;
			angle2=0.0;
			angle1=0.0;
			life2--;
		}
		printf("lief........................... %d\n",life);
	}


	if(fall==1 && win==0){
		if(life==1){
			life--;
		}
		if(life==0)
		{
			t3dDraw3D(str,0,0,0.2f);
		}


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

	//}

	glFlush();
	glutSwapBuffers();

}


// Function to handle all calculations in the scene
// updated evry 10 milliseconds
void update(int value) {
	_angle += 5.0f;
	if (_angle > 360) {
		_angle -= 360;
	}

		if(aagvar==0)
			aag+=0.05;
		if(aag>4.5)
			aagvar=1;
		if(aagvar==1)
			aag-=0.05;
		if(aag<3)
			aagvar=0;
	
if(counter1 < 11)
		counter1 ++;
	else
		counter1 = 0;

	if(counter < 11)
		counter ++;
	else
		counter = 0;
	yRotated+=2.0f;
	rot=rot+0.1f;	
	if(pause1%2==0){

		if(fall==1 && win==0){go_y-=0.1f;}
		if(fall2==1){go_y2=-0.1f;}
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
		if(chalokaflag==0)
			chalo-=0.05;
		if(chalo>1.8)
			chalokaflag=0;
		if(chalokaflag==1)
			chalo+=0.05;
		if(chalo<-2.0)
			chalokaflag=1;
		//if(naa1==0)
		//{
		if(chalokaflag1==0)
			chalo1-=0.05;
		if(chalo1>3)
			chalokaflag1=0;
		if(chalokaflag1==1)
			chalo1+=0.05;
		if(chalo1<0)
			chalokaflag1=1;
		//}
	}
	for(int h = 1; h <= shoot ; h++)
	{
		if(gundir[h] == 0)  //down
		{
			if(level == 2)
				gunarr[h].z += 1.1f;
			else
				gunarr[h].z += 0.1f;
		}
		if(gundir[h] == 1)  //right
		{
			if(level == 2)
				gunarr[h].x += 1.1f;
			else
				gunarr[h].x += 0.1f;
		}
		if(gundir[h] == 2)  //up
		{
			if(level == 2)
				gunarr[h].z -= 1.1f;
			else
				gunarr[h].z -= 0.1f;
		}
		if(gundir[h] == 3)  //left
		{
			if(level == 2)
				gunarr[h].x -= 1.1f;
			else
				gunarr[h].x -= 1.1f;
		}
	}
	//   drawScene();
	glutTimerFunc(90, update, 0);
}
/*void waterfall(int value)
  {
  if(counter<11)
  counter++; 
  else
  counter=0;

  printf("counter...%d\n");
  Image* image21 = loadBMP("0.bmp");//mount //front
  if(counter%12==0)
  image21 = loadBMP("0.bmp");//mount //front
  else if(counter%12==1)
  image21 = loadBMP("1.bmp");//mount //front
  else if(counter%12==2)
  image21 = loadBMP("2.bmp");//mount //front
  else if(counter%12==3)
  image21 = loadBMP("3.bmp");//mount //front
  else if(counter%12==4)
  image21 = loadBMP("4.bmp");//mount //front
  else if(counter%12==5)
  image21 = loadBMP("5.bmp");//mount //front
  else if(counter%12==6)
  image21 = loadBMP("6.bmp");//mount //front
  else if(counter%12==7)
  image21 = loadBMP("7.bmp");//mount //front
  else if(counter%12==8)
  image21 = loadBMP("8.bmp");//mount //front
  else if(counter%12==9)
  image21 = loadBMP("9.bmp");//mount //front
  else if(counter%12==10)
  image21 = loadBMP("10.bmp");//mount //front
  else if(counter%12==11)
  image21 = loadBMP("11.bmp");//mount //front

  _textureId3 = loadTexture(image21);

  delete image21;*/
//	glutTimerFunc(24000, update, 0);

//}


void drawRobot()
{
	if(level==1)
	{

		moretiles(5,-0.5, -0.5+2);
		moretiles(5.5,-0.5, 0.1+2);
		moretiles(7,-0.5, -1.5+2);
		moretiles(6,-0.5, 0.5+2);
		moretiles(8.5,-0.5, -0.5+2);

		moretiles(5-1,-0.5, -0.5+5);
		moretiles(5.5-1,-0.5, -0.1+5);
		moretiles(7-1,-0.5, -1.5+5);
		moretiles(6-1,-0.5, 0.5+5);
		moretiles(8.5-1,-0.5, -0.5+5);

		moretiles(6.5-2,-0.5, -0.5+8);
		moretiles(5.5-2,-0.5, 0.1+8);
		moretiles(7-2,-0.5, -1.5+8);
		moretiles(6-2,-0.5, 0.5+8);
		moretiles(8.5-2,-0.5, -0.5+8);


		moretiles(3,-0.5, -0.5+2);
		moretiles(3.5,-0.5, 0.1+2);
		moretiles(4,-0.5, -1.5+2);
		moretiles(4,-0.5, 0.5+2);
		moretiles(4.5,-0.5, -0.5+2);

		moretiles(3,-0.5, -0.5+3);
		moretiles(3.5,-0.5, 0.1+3);
		moretiles(4,-0.5, -1.5+3);
		moretiles(4,-0.5, 0.5+3);
		moretiles(4.5,-0.5, -0.5+3);


		moretiles(2,-0.5, -0.5+6);
		moretiles(2.5,-0.5, 0.1+6);
		moretiles(3,-0.5, -1.5+6);
		moretiles(4,-0.5, 0.5+6);
		moretiles(3.5,-0.5, -0.5+6);


		moretiles(1,-0.5, -0.5+2);
		moretiles(2.5,-0.5, 0.1+2);
		moretiles(1,-0.5, -1.5+2);
		moretiles(2,-0.5, 0.5+2);
		moretiles(2.5,-0.5, -0.5+2);

		/*
		   moretiles(1,-0.5, -0.5+3);
		   moretiles(2.5,-0.5, 0.1+3);
		   moretiles(1,-0.5, -1.5+3);
		   moretiles(2,-0.5, 0.5+3);
		   moretiles(2.5,-0.5, -0.5+3);
		 */

		///////
		moretiles(-1,-0.5, -0.5-2+8);
		moretiles(-1.5,-0.5, 0.1-2+8);
		moretiles(-2,-0.5, -1.5-2+8);
		moretiles(0,-0.5, 0.5-2+8);
		moretiles(1.5,-0.5, -0.5-2+8);

		moretiles(2,-0.5, -0.5-5+8);
		moretiles(1+0.5,-0.5, -0.1-5+7.5);
		moretiles(0,-0.5, -1.5-5+8.5);
		moretiles(4,-0.5, 0.5-5+7);
		moretiles(5,-0.5, -0.5-5+7);
		///////////
		moretiles(-5,-0.5, -0.5+2);
		moretiles(-5.5,-0.5, 0.1+2);
		moretiles(-7,-0.5, -1.5+2);
		moretiles(-6,-0.5, 0.5+2);
		moretiles(-8.5,-0.5, -0.5+2);

		moretiles(-5-1,-0.5, -0.5+5);
		moretiles(-5.5-1,-0.5, -0.1+5);
		moretiles(-7-1,-0.5, -1.5+5);
		moretiles(-6-1,-0.5, 0.5+5);
		moretiles(-8.5-1,-0.5, -0.5+5);

		moretiles(-6.5-2,-0.5, -0.5+8);
		moretiles(-5.5-2,-0.5, 0.1+8);
		moretiles(-7-2,-0.5, -1.5+8);
		moretiles(-6-2,-0.5, 0.5+8);
		moretiles(-8.5-2,-0.5, -0.5+8);

		moretiles(-3,-0.5, -0.5+2);
		moretiles(-3.5,-0.5, 0.1+2);
		moretiles(-4,-0.5, -1.5+2);
		moretiles(-4,-0.5, 0.5+2);
		moretiles(-4.5,-0.5, -0.5+2);

		moretiles(-3,-0.5, -0.5+3);
		moretiles(-3.5,-0.5, 0.1+3);
		moretiles(-4,-0.5, -1.5+3);
		moretiles(-4,-0.5, 0.5+3);
		moretiles(-4.5,-0.5, -0.5+3);

		moretiles(-2,-0.5, -0.5+6);
		moretiles(-2.5,-0.5, 0.1+6);
		moretiles(-3,-0.5, -1.5+6);
		moretiles(-4,-0.5, 0.5+6);
		moretiles(-3.5,-0.5, -0.5+6);


		moretiles(-1,-0.5, -0.5+2);
		moretiles(-2.5,-0.5, 0.1+2);
		moretiles(-1,-0.5, -1.5+2);
		moretiles(-2,-0.5, 0.5+2);
		moretiles(-2.5,-0.5, -0.5+2);



		moretiles(-1,-0.5, -0.5+3);
		moretiles(-2.5,-0.5, 0.1+3);
		moretiles(-1,-0.5, -1.5+3);
		moretiles(-2,-0.5, 0.5+3);
		moretiles(-2.5,-0.5, -0.5+3);
	}
	if(multiplay==1)
	{
		glPushMatrix(); 
		glColor3f(0,0,1);
		//glTranslatef(0,-0.5,0);
		//glTranslatef(1.7,0.0,2.2);
		glRotatef(gtheta2,0,1,0);
		if(fall2==1)
		{
			glTranslatef(move_x2,go_y2,move_z2);
		}
		else
			glTranslatef(move_x2,move_y2,move_z2);

		glPushMatrix();
		glEnable(GL_COLOR_MATERIAL);    // Enable coloring

		glDisable(GL_TEXTURE_2D);
		//	glColor3f(0,0,1);
		if(g2%3==0)
		{	
			if(pmodel2)
			{
				glmDelete(pmodel2);
				pmodel2=NULL;
			}

			if (!mod_) 
			{   	
				if(gun2==0)
					strcpy(temp, "grim_stand_f.obj");
				else if(gun2==1)
					strcpy(temp, "stand_gun.obj");
				//		                strcpy(temp, "right_leg.obj");
				//	            if(count % 3 == 2)
				//			                strcpy(temp,"left_f.obj");
				mod_ = glmReadOBJ(temp);     
				if (!mod_) exit(0);
				glmUnitize(mod_);
				glmFacetNormals(mod_);     
				glmVertexNormals(mod_, 90.0);

			}

			ok2=0;
			if(person2%2==1 && indx2==0)
			{ok2=1;}
			if(ok2!=1){
				//glScalef(0.5,0.5,0.5);
				glScalef(0.4,0.4,0.4);
				if(level==2)
					glScalef(15,15,15);
				if(level==3)
					glScalef(5,5,5);
				glmDraw(mod_, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
				//glmDraw(mod, GLM_SMOOTH | GLM_MATERIAL);
			}	//glPopMatrix();
		}
		else if(g2%3==1)
		{    
			//glPushMatrix();

			if(mod_)
			{glmDelete(mod_);
				mod_=NULL;}
			if(!mod2_ )
			{
				if(gun2==0)
					strcpy(temp, "right_leg.obj");
				else if(gun2==1)
					strcpy(temp, "right_gun_f.obj");
				//	strcpy(temp,"orig1.obj");
				mod2_ = glmReadOBJ(temp);
				//mod2 = glmReadOBJ("orig1.obj");
				if(!mod2_) exit(0);
				glmUnitize(mod2_);
				glmFacetNormals(mod2_);
				glmVertexNormals(mod2_, 90.0);
				//glmDimensions(mod2, dim);
				//printf("%f %f %f\n",dim[0],dim[1],dim[2]);
			}
			ok2=0;
			if(person2%2==1 && indx2==0)
			{ok2=1;}
			if(ok2!=1){
				glScalef(0.4,0.4,0.4);
				if(level==2)
					glScalef(15,15,15);
				if(level==3)
					glScalef(5,5,5);
				glmDraw(mod2_, GLM_SMOOTH | GLM_MATERIAL);
			}
		}
		else if(g2%3==2)
		{
			if(mod2_){
				glmDelete(mod2_);
				mod2_=NULL;}
			if (!pmodel2) 
			{   	//strcpy(temp, "grim_stand_f.obj");
				//		                strcpy(temp, "right_leg.obj");
				//	            if(count % 3 == 2)
				if(gun2==0)
					strcpy(temp,"left_f.obj");
				else if(gun2==1)
					strcpy(temp,"left_gun.obj");
				pmodel2 = glmReadOBJ(temp);     
				if (!pmodel2) exit(0);
				glmUnitize(pmodel2);
				glmFacetNormals(pmodel2);     
				glmVertexNormals(pmodel2, 90.0);

			}

			ok2=0;
			if(person2%2==1 && indx2==0)
			{ok2=1;}
			if(ok2!=1){
				glScalef(0.4,0.4,0.4);
				if(level==2)
					glScalef(15,15,15);
				if(level==3)
					glScalef(5,5,5);
				glmDraw(pmodel2, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
				//glmDraw(mod, GLM_SMOOTH | GLM_MATERIAL);
			}	//glPopMatrix();
		}
		glPopMatrix();
		glPopMatrix();
	}
	if(level==1)
	{
		glPushMatrix(); 

		glTranslatef(1,0,9.2);

		moretiles(2.0-1,-0.5,5-9.2);
		moretiles(2-1,-0.5,1-9.2);
		moretiles(1-1,-0.5,7-9.2);
		moretiles(2.5-1,-0.5,8-9.2-chalo1);
		//1.5,-0.5,-1.2
		moretiles(3-1,-0.5, 8-9.2-chalo1);
		moretiles(1+chalo-1,-0.5,8.5-9.2);//moving tile
		moretiles(0,-0.5,-0.2);

		glPopMatrix(); 

	}

	if(naa1==1)
	{
		glPushMatrix(); 
		//glColor3f(1,1,1);
		//glTranslatef(0,-0.5,0);
		glTranslatef(1.7,0.0,4.2);
		glRotatef(gtheta,0,1,0);
		if(fall==1)
		{
			glTranslatef(move_x,go_y,move_z);
		}
		else
			glTranslatef(move_x,move_y,move_z);
		//	printf("y..%f z..%f\n",move_y,move_z);
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


		glPushMatrix();
		glEnable(GL_COLOR_MATERIAL);    // Enable coloring

		glDisable(GL_TEXTURE_2D);
		glColor3f(0,1,1);
		if(g%3==0)
		{	
			if(pmodel1)
			{
				glmDelete(pmodel1);
				pmodel1=NULL;}

			if (!mod) 
			{   	
				if(gun==0)
					strcpy(temp, "grim_stand_f.obj");
				else if(gun==1)
					strcpy(temp, "stand_gun.obj");
				//		                strcpy(temp, "right_leg.obj");
				//	            if(count % 3 == 2)
				//			                strcpy(temp,"left_f.obj");
				mod = glmReadOBJ(temp);     
				if (!mod) exit(0);
				glmUnitize(mod);
				glmFacetNormals(mod);     
				glmVertexNormals(mod, 90.0);

			}

			ok=0;
			if(person%2==1 && indx==0)
			{ok=1;}
			if(ok!=1){
				//glScalef(0.5,0.5,0.5);
				glScalef(0.4,0.4,0.4);
				if(level==2)
					glScalef(15,15,15);
				if(level==3)
					glScalef(5,5,5);
				glmDraw(mod, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
				//glmDraw(mod, GLM_SMOOTH | GLM_MATERIAL);
			}	//glPopMatrix();
		}
		else if(g%3==1)
		{    
			//glPushMatrix();

			if(mod)
			{glmDelete(mod);
				mod=NULL;}
			if(!mod2 )
			{
				if(gun==0)
					strcpy(temp, "right_leg.obj");
				else if(gun==1)
					strcpy(temp, "right_gun_f.obj");
				//	strcpy(temp,"orig1.obj");
				mod2 = glmReadOBJ(temp);
				//mod2 = glmReadOBJ("orig1.obj");
				if(!mod2) exit(0);
				glmUnitize(mod2);
				glmFacetNormals(mod2);
				glmVertexNormals(mod2, 90.0);
				//glmDimensions(mod2, dim);
				//printf("%f %f %f\n",dim[0],dim[1],dim[2]);
			}
			ok=0;
			if(person%2==1 && indx==0)
			{ok=1;}
			if(ok!=1){
				glScalef(0.4,0.4,0.4);
				if(level==2)
					glScalef(15,15,15);
				if(level==3)
					glScalef(5,5,5);
				glmDraw(mod2, GLM_SMOOTH | GLM_MATERIAL);
			}
		}
		else if(g%3==2)
		{
			if(mod2){
				glmDelete(mod2);
				mod2=NULL;}
			if (!pmodel1) 
			{   	//strcpy(temp, "grim_stand_f.obj");
				//		                strcpy(temp, "right_leg.obj");
				//	            if(count % 3 == 2)
				if(gun==0)
					strcpy(temp,"left_f.obj");
				else if(gun==1)
					strcpy(temp,"left_gun.obj");
				pmodel1 = glmReadOBJ(temp);     
				if (!pmodel1) exit(0);
				glmUnitize(pmodel1);
				glmFacetNormals(pmodel1);     
				glmVertexNormals(pmodel1, 90.0);

			}

			ok=0;
			if(person%2==1 && indx==0)
			{ok=1;}
			if(ok!=1){
				glScalef(0.4,0.4,0.4);
				if(level==2)
					glScalef(15,15,15);
				if(level==3)
					glScalef(5,5,5);
				glmDraw(pmodel1, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
				//glmDraw(mod, GLM_SMOOTH | GLM_MATERIAL);
			}	//glPopMatrix();
		}
		glPopMatrix();
		glPopMatrix();
		//ROBOT2
	}

	else
	{
		//naa1=1;
		glPushMatrix(); 
		//glColor3f(1,1,1);
		//glTranslatef(0,-0.5,0);
		glTranslatef(1,0,9.2);

		moretiles(2.0-1,-0.5,5-9.2);
		moretiles(2-1,-0.5,1-9.2);
		moretiles(1-1,-0.5,7-9.2);
		moretiles(2.5-1,-0.5,8-9.2-chalo1);
		//1.5,-0.5,-1.2
		moretiles(3-1,-0.5, 8-9.2-chalo1);
		moretiles(1+chalo-1,-0.5,8.5-9.2);//moving tile
		moretiles(0,-0.5,-0.2);

		glRotatef(gtheta,0,1,0);
		if(fall==1)
		{
			glTranslatef(move_x,go_y,move_z);
		}
		if(naa==0 && lookz+9.2 > 8.3 && lookz + 9.2 < 8.7 && lookx+1 < 1.1 && lookx+1 > 0.9 && chalo<0.2 && chalo >-0.2 )
			//glTranslatef(move_x-chalo,move_y,move_z);
		{
			//      glTranslatef(0,0,0);
			imontile=1;
		}
		if(naa1==0 && lookx < 1.8 && lookx> 1.2 && lookz < -0.8 && lookz > -1.4 )
		{
			transtile=1;
		}

		if(fall!=1 && imontile==0 && transtile==0)
			glTranslatef(move_x,move_y,move_z);

		if(transtile==1)
		{
			if(indx==2)
				glTranslatef(0,move_y,chalo1);
			if(indx==0)
				glTranslatef(0,move_y,-chalo1);
			if(indx==1)
				glTranslatef(chalo1,move_y,0);
			if(indx==3)
				glTranslatef(-chalo1,move_y,0);
		}
		//glTranslatef(-chalo1,move_y,0);
		//	moretiles(2.5-1,-0.5,8-9.2-chalo1);
		if( transtile==1 && lookx < 1.0 )
		{
			transtile=0;
			move_x-=chalo1;
			move_z+=1;
			naa1=1;

		}

		if(imontile==1 && naa==0)
		{
			if(indx==0)
			{
				glTranslatef(move_x+chalo,move_y,move_z);
			}
			if(indx==1)
				glTranslatef(move_x,move_y,move_z+chalo);
			if(indx==3)
				glTranslatef(move_x,move_y,move_z-chalo);
			if(indx==2)
			{

				glTranslatef(move_x-chalo,move_y,move_z);
			}
		}
		if(
				(lookz+9.2 > 8.2 && lookz + 9.2 < 8.8
				 && lookx+1 < 1.3 && lookx+1 > 0.7 )

				&& imontile==1 && naa==0
		  )

		{
			fall=0;
		}
		else if((lookz+9.2 > 8.7 && lookz + 9.2 < 9.4
					&& lookx+1 < 1.3 && lookx+1 > 0.7
			)
		       )
		{

			fall=0;
		}
		else if((move_z > 0.6   && move_z <1.4 && 
					move_x-chalo < -1.2  && move_x-chalo > -1.8 ))
		{
			move_x=move_x-chalo;
			printf("mm\n");
			imontile=0;
			fall=0;
			naa=1;
		}
		else if(move_x<-0.8 && move_x >-2.2 && move_z <1.5 && move_z > 0.5)
		{//-1.45,1
			fall=0;
			imontile=0;
		}
		else if(lookz < -1)
			fall=0;
		else
		{
			fall=1;
			imontile=0;
		}

		printf("dekh x: %f y : %f z: %f\n",move_x,move_y,move_z);
		////////////////////////////////////////////////////////////////
		//	printf("y..%f z..%f\n",move_y,move_z);
		// Set the camera

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

		//glPopMatrix();

		glPushMatrix();
		glEnable(GL_COLOR_MATERIAL);    // Enable coloring

		glDisable(GL_TEXTURE_2D);
		glColor3f(0,1,1);
		if(g%3==0)
		{	
			if(pmodel1)
			{
				glmDelete(pmodel1);
				pmodel1=NULL;}

			if (!mod) 
			{   	
				if(gun==0)
					strcpy(temp, "grim_stand_f.obj");
				else if(gun==1)
					strcpy(temp, "stand_gun.obj");
				//		                strcpy(temp, "right_leg.obj");
				//	            if(count % 3 == 2)
				//			                strcpy(temp,"left_f.obj");
				mod = glmReadOBJ(temp);     
				if (!mod) exit(0);
				glmUnitize(mod);
				glmFacetNormals(mod);     
				glmVertexNormals(mod, 90.0);

			}

			ok=0;
			if(person%2==1 && indx==0)
			{ok=1;}
			if(ok!=1){
				//glScalef(0.5,0.5,0.5);
				glScalef(0.4,0.4,0.4);
				if(level==2)
					glScalef(15,15,15);
				glmDraw(mod, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
				//glmDraw(mod, GLM_SMOOTH | GLM_MATERIAL);
			}	//glPopMatrix();
		}
		else if(g%3==1)
		{    
			//glPushMatrix();

			if(mod)
			{glmDelete(mod);
				mod=NULL;}
			if(!mod2 )
			{
				if(gun==0)
					strcpy(temp, "right_leg.obj");
				else if(gun==1)
					strcpy(temp, "right_gun_f.obj");
				//	strcpy(temp,"orig1.obj");
				mod2 = glmReadOBJ(temp);
				//mod2 = glmReadOBJ("orig1.obj");
				if(!mod2) exit(0);
				glmUnitize(mod2);
				glmFacetNormals(mod2);
				glmVertexNormals(mod2, 90.0);
				//glmDimensions(mod2, dim);
				//printf("%f %f %f\n",dim[0],dim[1],dim[2]);
			}
			ok=0;
			if(person%2==1 && indx==0)
			{ok=1;}
			if(ok!=1){
				glScalef(0.4,0.4,0.4);
				if(level==2)
					glScalef(15,15,15);
				glmDraw(mod2, GLM_SMOOTH | GLM_MATERIAL);
			}
		}
		else if(g%3==2)
		{
			if(mod2){
				glmDelete(mod2);
				mod2=NULL;}
			if (!pmodel1) 
			{   	//strcpy(temp, "grim_stand_f.obj");
				//		                strcpy(temp, "right_leg.obj");
				//	            if(count % 3 == 2)
				if(gun==0)
					strcpy(temp,"left_f.obj");
				else if(gun==1)
					strcpy(temp,"left_gun.obj");
				pmodel1 = glmReadOBJ(temp);     
				if (!pmodel1) exit(0);
				glmUnitize(pmodel1);
				glmFacetNormals(pmodel1);     
				glmVertexNormals(pmodel1, 90.0);

			}

			ok=0;
			if(person%2==1 && indx==0)
			{ok=1;}
			if(ok!=1){
				glScalef(0.4,0.4,0.4);
				if(level==2)
					glScalef(15,15,15);
				glmDraw(pmodel1, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
				//glmDraw(mod, GLM_SMOOTH | GLM_MATERIAL);
			}	//glPopMatrix();
		}
		glPopMatrix();

		if(naa1==1)
		{
			move_x=0.0;
			move_y=0.0;
			move_z=0.0;
			lookx=0.0f;looky=0.0f;lookz=0.0f;
			down=0;
			jump=0;
			pindx=-1,indx=-1;

			move_x2=0.0f;move_y2=0.0f;move_z2=0.0f;
			lookx2=0.0f;looky2=0.0f;lookz2=0.0f;
			down2=0;
			jump2=0;
			pindx2=-1,indx2=-1;
			intr=0;
			thirdp=0;
			tileview=0;
			block=0;
			roboup=0;
			incr=1;
			upview=0;
			flag=0;
			gazeno=0;
			angle2=0.0;
			angle1=0.0;
		}

		glPopMatrix();




	}
}

/*
   void drawRobot()
   {

   moretiles(5,-0.5, -0.5+2);
   moretiles(5.5,-0.5, 0.1+2);
   moretiles(7,-0.5, -1.5+2);
   moretiles(6,-0.5, 0.5+2);
   moretiles(8.5,-0.5, -0.5+2);

   moretiles(5-1,-0.5, -0.5+5);
   moretiles(5.5-1,-0.5, -0.1+5);
   moretiles(7-1,-0.5, -1.5+5);
   moretiles(6-1,-0.5, 0.5+5);
   moretiles(8.5-1,-0.5, -0.5+5);

   moretiles(6.5-2,-0.5, -0.5+8);
   moretiles(5.5-2,-0.5, 0.1+8);
   moretiles(7-2,-0.5, -1.5+8);
   moretiles(6-2,-0.5, 0.5+8);
   moretiles(8.5-2,-0.5, -0.5+8);

   moretiles(3,-0.5, -0.5+2);
   moretiles(3.5,-0.5, 0.1+2);
   moretiles(4,-0.5, -1.5+2);
   moretiles(4,-0.5, 0.5+2);
   moretiles(4.5,-0.5, -0.5+2);

   moretiles(3,-0.5, -0.5+3);
   moretiles(3.5,-0.5, 0.1+3);
   moretiles(4,-0.5, -1.5+3);
   moretiles(4,-0.5, 0.5+3);
   moretiles(4.5,-0.5, -0.5+3);

   moretiles(2,-0.5, -0.5+6);
   moretiles(2.5,-0.5, 0.1+6);
   moretiles(3,-0.5, -1.5+6);
   moretiles(4,-0.5, 0.5+6);
   moretiles(3.5,-0.5, -0.5+6);


   moretiles(1,-0.5, -0.5+2);
   moretiles(2.5,-0.5, 0.1+2);
   moretiles(1,-0.5, -1.5+2);
   moretiles(2,-0.5, 0.5+2);
   moretiles(2.5,-0.5, -0.5+2);



   moretiles(1,-0.5, -0.5+3);
   moretiles(2.5,-0.5, 0.1+3);
   moretiles(1,-0.5, -1.5+3);
   moretiles(2,-0.5, 0.5+3);
   moretiles(2.5,-0.5, -0.5+3);

///////
moretiles(5,-0.5, -0.5-2);
moretiles(5.5,-0.5, 0.1-2);
moretiles(7,-0.5, -1.5-2);
moretiles(6,-0.5, 0.5-2);
moretiles(8.5,-0.5, -0.5-2);

moretiles(5-1,-0.5, -0.5-5);
moretiles(5.5-1,-0.5, -0.1-5);
moretiles(7-1,-0.5, -1.5-5);
moretiles(6-1,-0.5, 0.5-5);
moretiles(8.5-1,-0.5, -0.5-5);
///////////

moretiles(-5,-0.5, -0.5+2);
moretiles(-5.5,-0.5, 0.1+2);
moretiles(-7,-0.5, -1.5+2);
moretiles(-6,-0.5, 0.5+2);
moretiles(-8.5,-0.5, -0.5+2);

moretiles(-5-1,-0.5, -0.5+5);
moretiles(-5.5-1,-0.5, -0.1+5);
moretiles(-7-1,-0.5, -1.5+5);
moretiles(-6-1,-0.5, 0.5+5);
moretiles(-8.5-1,-0.5, -0.5+5);

moretiles(-6.5-2,-0.5, -0.5+8);
moretiles(-5.5-2,-0.5, 0.1+8);
moretiles(-7-2,-0.5, -1.5+8);
moretiles(-6-2,-0.5, 0.5+8);
moretiles(-8.5-2,-0.5, -0.5+8);

moretiles(-3,-0.5, -0.5+2);
moretiles(-3.5,-0.5, 0.1+2);
moretiles(-4,-0.5, -1.5+2);
moretiles(-4,-0.5, 0.5+2);
moretiles(-4.5,-0.5, -0.5+2);

moretiles(-3,-0.5, -0.5+3);
moretiles(-3.5,-0.5, 0.1+3);
moretiles(-4,-0.5, -1.5+3);
moretiles(-4,-0.5, 0.5+3);
moretiles(-4.5,-0.5, -0.5+3);

moretiles(-2,-0.5, -0.5+6);
moretiles(-2.5,-0.5, 0.1+6);
moretiles(-3,-0.5, -1.5+6);
moretiles(-4,-0.5, 0.5+6);
moretiles(-3.5,-0.5, -0.5+6);


moretiles(-1,-0.5, -0.5+2);
moretiles(-2.5,-0.5, 0.1+2);
moretiles(-1,-0.5, -1.5+2);
moretiles(-2,-0.5, 0.5+2);
moretiles(-2.5,-0.5, -0.5+2);



moretiles(-1,-0.5, -0.5+3);
moretiles(-2.5,-0.5, 0.1+3);
moretiles(-1,-0.5, -1.5+3);
moretiles(-2,-0.5, 0.5+3);
moretiles(-2.5,-0.5, -0.5+3);


//naa1=1;
glPushMatrix(); 
//glColor3f(1,1,1);
//glTranslatef(0,-0.5,0);
if(naa1==1)
{
	glTranslatef(1.7,0.0,4.2);

	if(fall==1)
	{
		glTranslatef(move_x,go_y,move_z);
	}
	else
		glTranslatef(move_x,move_y,move_z);
}
////////////////////////////////////////////////
else
{
	glTranslatef(1,0,9.2);

	moretiles(2.0-1,-0.5,5-9.2);
	moretiles(2-1,-0.5,1-9.2);
	moretiles(1-1,-0.5,7-9.2);
	moretiles(2.5-1,-0.5,8-9.2-chalo1);
	//1.5,-0.5,-1.2
	moretiles(3-1,-0.5, 8-9.2-chalo1);
	moretiles(1+chalo-1,-0.5,8.5-9.2);//moving tile
	moretiles(0,-0.5,-0.2);

	glRotatef(gtheta,0,1,0);
	if(fall==1)
	{
		glTranslatef(move_x,go_y,move_z);
	}
	if(naa==0 && lookz+9.2 > 8.3 && lookz + 9.2 < 8.7 && lookx+1 < 1.1 && lookx+1 > 0.9 && chalo<0.2 && chalo >-0.2 )
		//glTranslatef(move_x-chalo,move_y,move_z);
	{
		//      glTranslatef(0,0,0);
		imontile=1;
	}
	if(naa1==0 && lookx < 1.8 && lookx> 1.2 && lookz < -0.8 && lookz > -1.4 )
	{
		transtile=1;
	}

	if(fall!=1 && imontile==0 && transtile==0)
		glTranslatef(move_x,move_y,move_z);

	if(transtile==1)
		if(indx==2)
			glTranslatef(0,move_y,chalo1);
	if(indx==0)
		glTranslatef(0,move_y,-chalo1);
	if(indx==1)
		glTranslatef(chalo1,move_y,0);
	if(indx==3)
		glTranslatef(-chalo1,move_y,0);

	//glTranslatef(-chalo1,move_y,0);
	//	moretiles(2.5-1,-0.5,8-9.2-chalo1);
	if( transtile==1 && lookx < 1.0 )
	{
		transtile=0;
		move_x-=chalo1;
		move_z+=1;
		naa1=1;

	}

	if(imontile==1 && naa==0)
	{
		if(indx==0)
		{
			glTranslatef(move_x+chalo,move_y,move_z);
		}
		if(indx==1)
			glTranslatef(move_x,move_y,move_z+chalo);
		if(indx==3)
			glTranslatef(move_x,move_y,move_z-chalo);
		if(indx==2)
		{

			glTranslatef(move_x-chalo,move_y,move_z);
		}
	}
	if(
			(lookz+9.2 > 8.2 && lookz + 9.2 < 8.8
			 && lookx+1 < 1.3 && lookx+1 > 0.7 )

			&& imontile==1 && naa==0
	  )

	{
		fall=0;
	}
	else if((lookz+9.2 > 8.7 && lookz + 9.2 < 9.4
				&& lookx+1 < 1.3 && lookx+1 > 0.7
		)
	       )
	{

		fall=0;
	}
	else if((move_z > 0.6   && move_z <1.4 && 
				move_x-chalo < -1.2  && move_x-chalo > -1.8 ))
	{
		move_x=move_x-chalo;
		printf("mm\n");
		imontile=0;
		fall=0;
		naa=1;
	}
	else if(move_x<-0.8 && move_x >-2.2 && move_z <1.5 && move_z > 0.5)
	{//-1.45,1
		fall=0;
		imontile=0;
	}
	else if(lookz < -1)
		fall=0;
	else
	{
		fall=1;
		imontile=0;
	}

	printf("dekh x: %f y : %f z: %f\n",move_x,move_y,move_z);
	if(naa1==1)
	{
		move_x=0.0;
		move_y=0.0;
		move_z=0.0;
		lookx=0.0f;looky=0.0f;lookz=0.0f;
		down=0;
		jump=0;
		pindx=-1,indx=-1;

		move_x2=0.0f;move_y2=0.0f;move_z2=0.0f;
		lookx2=0.0f;looky2=0.0f;lookz2=0.0f;
		down2=0;
		jump2=0;
		pindx2=-1,indx2=-1;
		intr=0;
		thirdp=0;
		tileview=0;
		block=0;
		roboup=0;
		incr=1;
		upview=0;
		flag=0;
		gazeno=0;
		angle2=0.0;
		angle1=0.0;
	}
}
////////////////////////////////////////////////////////////////
//	printf("y..%f z..%f\n",move_y,move_z);
// Set the camera

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

//glPopMatrix();

glPushMatrix();
glEnable(GL_COLOR_MATERIAL);    // Enable coloring

glDisable(GL_TEXTURE_2D);
glColor3f(0,1,1);
if(g%3==0)
{	
	if(pmodel1)
	{
		glmDelete(pmodel1);
		pmodel1=NULL;}

	if (!mod) 
	{   	
		if(gun==0)
			strcpy(temp, "grim_stand_f.obj");
		else if(gun==1)
			strcpy(temp, "stand_gun.obj");
		//		                strcpy(temp, "right_leg.obj");
		//	            if(count % 3 == 2)
		//			                strcpy(temp,"left_f.obj");
		mod = glmReadOBJ(temp);     
		if (!mod) exit(0);
		glmUnitize(mod);
		glmFacetNormals(mod);     
		glmVertexNormals(mod, 90.0);

	}

	ok=0;
	if(person%2==1 && indx==0)
	{ok=1;}
	if(ok!=1){
		//glScalef(0.5,0.5,0.5);
		glScalef(0.4,0.4,0.4);
		if(level==2)
			glScalef(15,15,15);
		glmDraw(mod, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
		//glmDraw(mod, GLM_SMOOTH | GLM_MATERIAL);
	}	//glPopMatrix();
}
else if(g%3==1)
{    
	//glPushMatrix();

	if(mod)
	{glmDelete(mod);
		mod=NULL;}
	if(!mod2 )
	{
		if(gun==0)
			strcpy(temp, "right_leg.obj");
		else if(gun==1)
			strcpy(temp, "right_gun_f.obj");
		//	strcpy(temp,"orig1.obj");
		mod2 = glmReadOBJ(temp);
		//mod2 = glmReadOBJ("orig1.obj");
		if(!mod2) exit(0);
		glmUnitize(mod2);
		glmFacetNormals(mod2);
		glmVertexNormals(mod2, 90.0);
		//glmDimensions(mod2, dim);
		//printf("%f %f %f\n",dim[0],dim[1],dim[2]);
	}
	ok=0;
	if(person%2==1 && indx==0)
	{ok=1;}
	if(ok!=1){
		glScalef(0.4,0.4,0.4);
		if(level==2)
			glScalef(15,15,15);
		glmDraw(mod2, GLM_SMOOTH | GLM_MATERIAL);
	}
}
else if(g%3==2)
{
	if(mod2){
		glmDelete(mod2);
		mod2=NULL;}
	if (!pmodel1) 
	{   	//strcpy(temp, "grim_stand_f.obj");
		//		                strcpy(temp, "right_leg.obj");
		//	            if(count % 3 == 2)
		if(gun==0)
			strcpy(temp,"left_f.obj");
		else if(gun==1)
			strcpy(temp,"left_gun.obj");
		pmodel1 = glmReadOBJ(temp);     
		if (!pmodel1) exit(0);
		glmUnitize(pmodel1);
		glmFacetNormals(pmodel1);     
		glmVertexNormals(pmodel1, 90.0);

	}

	ok=0;
	if(person%2==1 && indx==0)
	{ok=1;}
	if(ok!=1){
		glScalef(0.4,0.4,0.4);
		if(level==2)
			glScalef(15,15,15);
		glmDraw(pmodel1, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
		//glmDraw(mod, GLM_SMOOTH | GLM_MATERIAL);
	}	//glPopMatrix();
}
glPopMatrix();
glPopMatrix();
}	
	*/
void drawLine()
{
	//    glPointSize(3.0);
	/*  for(int h = 1; h <= shoot ; h++)
	    {
	    if(gundir[h] == 0)  //down
	    gunarr[h].z += 0.1f;
	    if(gundir[h] == 1)  //right
	    gunarr[h].x += 0.1f;
	    if(gundir[h] == 2)  //up
	    gunarr[h].z -= 0.1f;
	    if(gundir[h] == 3)  //left
	    gunarr[h].x -= 0.1f;
	    }
	 */
	if(press == 1)
	{
		gunarr[shoot].x = lookx+1.7;
		gunarr[shoot].y = looky-0.1f;
		if(level==2)
			gunarr[shoot].y = looky-1.4f;

		gunarr[shoot].z = lookz+4.2;
		if(indx==0)
		{
			if(level == 2)
			{
				gunarr[shoot].x -= 2.8;
				gunarr[shoot].z += 4.3;
			}
			else
			{
				gunarr[shoot].x -= 0.18;
				gunarr[shoot].z += 0.3;
			}
		}
		if(indx==1)
		{
			if(level == 2)
			{
				gunarr[shoot].z += 4.0;
				gunarr[shoot].x += 4.30;


			}
			else
			{
				gunarr[shoot].z += 0.18;
				gunarr[shoot].x += 0.30;
			}
		}
		if(indx==2)
		{
			if(level == 2)
			{
				gunarr[shoot].x += 3;
				gunarr[shoot].z -= 7.30;

			}
			else
			{
				gunarr[shoot].x += 0.18;
				gunarr[shoot].z -= 0.30;
			}
		}
		if(indx==3)
		{
			if(level == 2)
			{
				gunarr[shoot].z -= 4.0;
				gunarr[shoot].x -= 4.30;

			}
			else
			{

				gunarr[shoot].z -= 0.18;
				gunarr[shoot].x -= 0.30;
			}
		}
		gundir[shoot] = indx;
		press = 0;
	}

	printf("gun arr : %f %f %f\n",gunarr[shoot].x,gunarr[shoot].y,gunarr[shoot].z);

	for(int h = 1; h <= shoot ; h++)
	{
		glEnable(GL_COLOR_MATERIAL);
		glDisable(GL_LIGHTING);
		glBegin(GL_LINES);
		glColor3f(1.0,0.0,0.0);
		glVertex3d(gunarr[h].x,gunarr[h].y,gunarr[h].z);
		//if(indx == 3) //left
		if(gundir[h] == 3)  //left
		{
			if(level == 2)
				glVertex3d(gunarr[h].x-1.1f,gunarr[h].y,gunarr[h].z);
			else
				glVertex3d(gunarr[h].x-0.1f,gunarr[h].y,gunarr[h].z);
		}
		if(gundir[h] == 1) //right
		{
			if(level == 2)
				glVertex3d(gunarr[h].x+1.1f,gunarr[h].y,gunarr[h].z);
			else
				glVertex3d(gunarr[h].x+0.1f,gunarr[h].y,gunarr[h].z);
		}
		if(gundir[h] == 0) //down
		{
			if(level == 2)
				glVertex3d(gunarr[h].x,gunarr[h].y,gunarr[h].z+1.1f);
			else
				glVertex3d(gunarr[h].x,gunarr[h].y,gunarr[h].z+0.1f);
		}
		if(gundir[h] == 2) //up
		{
			if(level == 2)
				glVertex3d(gunarr[h].x,gunarr[h].y,gunarr[h].z-1.1f);
			else
				glVertex3d(gunarr[h].x,gunarr[h].y,gunarr[h].z-0.1f);
		}
		glEnd();
	}
//	glColor3f(0,1,1);
}
void drawBox() {

	glEnable(GL_COLOR_MATERIAL);    // Enable coloring

	glDisable(GL_LIGHTING);
	//draw water
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	//glTranslatef(0,0,-20);
	if(counter == 0)
		glBindTexture(GL_TEXTURE_2D, _textureId30);
	if(counter == 1)
		glBindTexture(GL_TEXTURE_2D, _textureId31);
	if(counter == 2)
		glBindTexture(GL_TEXTURE_2D, _textureId32);
	if(counter == 3)
		glBindTexture(GL_TEXTURE_2D, _textureId33);
	if(counter == 4)
		glBindTexture(GL_TEXTURE_2D, _textureId34);
	if(counter == 5)
		glBindTexture(GL_TEXTURE_2D, _textureId35);
	if(counter == 6)
		glBindTexture(GL_TEXTURE_2D, _textureId36);
	if(counter == 7)
		glBindTexture(GL_TEXTURE_2D, _textureId37);
	if(counter == 8)
		glBindTexture(GL_TEXTURE_2D, _textureId38);
	if(counter == 9)
		glBindTexture(GL_TEXTURE_2D, _textureId39);
	if(counter == 10)
		glBindTexture(GL_TEXTURE_2D, _textureId310);
	if(counter == 11)
		glBindTexture(GL_TEXTURE_2D, _textureId311);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//left wall
	/*
	   glPushMatrix();
	   glTranslatef(-5,0,0);//2
	   glRotatef(90,0,1,0);
	   glBegin(GL_POLYGON);
	   glTexCoord2f(0.0f, 0.0f);
	   glVertex3f( -30, -40, -25 );
	   glTexCoord2f(1.0f, 0.0f);
	   glVertex3f( 25, -40, -25 );
	   glTexCoord2f(1.0f, 1.0f);
	   glVertex3f(  25, 40, -25 );
	   glTexCoord2f(0.0f, 1.0f);
	   glVertex3f(  -30,  40, -25 );

	   glEnd();
	   glPopMatrix();

	//rightwall
	glPushMatrix();
	glTranslatef(4,0,0);//3
	glRotatef(-90,0,1,0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f( -30, -40, -25 );
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f( 30, -40, -25 );
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(  30, 40, -25 );
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(  -30,  40, -25 );

	glEnd();
	glPopMatrix();
	 */
	/*
	//front wall
	glPushMatrix();
	glTranslatef(0,7,-100);

	glRotatef(-65,1,0,0);
	glBegin(GL_POLYGON);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f( -110, -60, -40 );
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f( 100, -60, -40 );
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(  120, 100, -40 );
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(  -130,  100, -40 );
	glEnd();
	glPopMatrix();
	 */

	glPushMatrix();
	glTranslatef(0,-20,0);
	glScalef(2.5,2.5,2.5);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f( -48, -10, -40 );
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f( 50, -10, -40 );
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(  50, 40, -40 );
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(  -48,  40, -40 );
	glEnd();
	glPopMatrix();


	//base wall
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//base
	glPushMatrix();
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f( -40, -1, 20 );
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(  40,  -1, 20 );
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(  40, -1, -2 );
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f( -40, -1, -2 );

	glEnd();
	glPopMatrix();



	glPopMatrix();
	/*

	   glTexCoord2f(0.0f, 0.0f);
	   glVertex3f(  10, -1, -10 );
	   glTexCoord2f(1.0f, 0.0f);
	   glVertex3f(  10,  -1, 10 );
	   glTexCoord2f(1.0f, 1.0f);
	   glVertex3f( -10, -1, -10 );
	   glTexCoord2f(0.0f, 1.0f);
	   glVertex3f( -10, -1, 10 );
	 */
	/*	   glTexCoord2f(0.0f, 0.0f);
		   glVertex3f(  80, -1, -20 );
		   glTexCoord2f(1.0f, 0.0f);
		   glVertex3f(  40,  -1, 20 );
		   glTexCoord2f(1.0f, 1.0f);
		   glVertex3f( -20, -1, -20 );
		   glTexCoord2f(0.0f, 1.0f);
		   glVertex3f( -40, -1, 80 );

	 */

	glDisable(GL_TEXTURE_2D);

	glPushMatrix();
	glTranslatef(0,-0.5,1);

	//numr=0;
	horz=0;
	float xb,zb,l=0.2,h=0.0005,b=0.2;
	xb=-2;
	while(xb<=2)
	{
		vert=0;
		horz++;
		zb=-3;
		while(zb<=3)
		{
			vert++;

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
					(horz==3 && vert==14) || (horz==5 && vert==14) ||
					(horz==4 && vert==14) || (horz==1 && vert==13) ||
					(horz==1 && vert==12) || (horz==1 && vert==6) ||
					(horz==3 && vert==3) || (horz==3 && vert==2) ||
					(horz==1 && vert==4) || (horz==4 && vert==1) ||
					(horz==6 && vert==6) || (horz==6 && vert==7) ||
					(horz==7 && vert==8) || (horz==7 && vert==7) ||
					(horz==1 && vert==4) || (horz==4 && vert==7) ||
					(horz==5 && vert==8) || (horz==6 && vert==9) ||
					(horz==9 && vert==10) || (horz==5 && vert==5) ||
					(horz==9 && vert==1) || (horz==6 && vert==2) ||
					(horz==8 && vert==10) || (horz==9 && vert==3))
			{
				//printf("%f %f\n",-2+8*0.45,-3+0*0.45);
				ok=1;
			}
			block=0;

			if(ok==0)
			{
				if((horz==6 && vert==11) ){h=1.0;
					block=1;
					box1=boundbox(box1,horz,-0.1,vert,h);
				}
				else if((horz==8 && vert==4) ){h=1.0;
					block=1;
					box2=boundbox(box2,horz,-0.1,vert,h);
				}
				else{h=0.05;}
				if((horz==6 && vert==3) || (horz==1 && vert == 10)){
					//glDisable(GL_TEXTURE_2D);
					glBindTexture(GL_TEXTURE_2D, _textureId4);

					//Bottom
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				}else{


					glEnable(GL_TEXTURE_2D);
					glBindTexture(GL_TEXTURE_2D, _textureId);

					//Bottom
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				}

				//Front-white

				glBegin(GL_POLYGON);
				glColor3f(   1.0,  1.0, 1.0 );
				//glColor3f(   1.0,  1.0,  0.0 );
				glTexCoord2f(0.0f, 0.0f);

				if(block==1){glVertex3f(-l,0,b);}else
					glVertex3f( -l, -h, b );

				glTexCoord2f(1.0f, 0.0f);
				if(block==1){glVertex3f(l,0,b);}else
					glVertex3f(  l, -h, b );

				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(  l,  h, b );

				glTexCoord2f(0.0f, 1.0f);
				glVertex3f( -l,  h, b );
				glEnd();


				// Purple side - RIGHT
				glBegin(GL_POLYGON);
				glColor3f(   1.0,  1.0, 1.0 );
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
						glPushMatrix();
						glColor3f(0,1,1);
						glScalef(0.1,0.1,0.1);
						glRotatef(_angle,1,0,0);
						glmDraw(coins, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
						glPopMatrix();
					}

					if(count2==0 && horz==5 && vert==6){
						glPushMatrix();
						glColor3f(0,1,1);
						glScalef(0.1,0.1,0.1);
						glRotatef(_angle,1,0,0);
						glmDraw(coins, GLM_SMOOTH | GLM_TEXTURE | GLM_MATERIAL);
						glPopMatrix();

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
		glEnable(GL_LIGHT1);

		glEnable(GL_NORMALIZE);

		GLfloat lightpos1[] = {lookx+1.7, 0.0, lookz+4.2, 0.0};
		glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightpos1 );
		glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180); // angle is 0 to 180
		glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 78); 
		glShadeModel(GL_SMOOTH);
		//	glEnable(GL_CULL_FACE);
		//	GLfloat lightpos[] = {0.5, 1.0, 1.0, 0.0};
		//	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
		Image* image = loadBMP("wood0.bmp");//wood3
		_textureId = loadTexture(image);
		Image* image1 = loadBMP("neel4.bmp");//base
		_textureId2 = loadTexture(image1);


	Image* image70 = loadBMP("a0.bmp");//mount //front
		_textureId70 = loadTexture(image70);
		Image* image71 = loadBMP("a1.bmp");
		_textureId71 = loadTexture(image71);
		Image* image72 = loadBMP("a2.bmp");
		_textureId72 = loadTexture(image72);
		Image* image73 = loadBMP("a3.bmp");
		_textureId73 = loadTexture(image73);
		Image* image74 = loadBMP("a4.bmp");
		_textureId74 = loadTexture(image74);
		Image* image75 = loadBMP("a5.bmp");
		_textureId75 = loadTexture(image75);
		Image* image76 = loadBMP("a6.bmp");
		_textureId76 = loadTexture(image76);
		Image* image77 = loadBMP("a7.bmp");
		_textureId77 = loadTexture(image77);
		Image* image78 = loadBMP("a8.bmp");
		_textureId78 = loadTexture(image78);
		Image* image79 = loadBMP("a9.bmp");
		_textureId79 = loadTexture(image79);
		Image* image710 = loadBMP("a10.bmp");
		_textureId710 = loadTexture(image710);
		Image* image711 = loadBMP("a11.bmp");
		_textureId711 = loadTexture(image711);



		Image* image20 = loadBMP("0.bmp");//mount //front
		_textureId30 = loadTexture(image20);
		Image* image21 = loadBMP("1.bmp");
		_textureId31 = loadTexture(image21);
		Image* image22 = loadBMP("2.bmp");
		_textureId32 = loadTexture(image22);
		Image* image23 = loadBMP("3.bmp");
		_textureId33 = loadTexture(image23);
		Image* image24 = loadBMP("4.bmp");
		_textureId34 = loadTexture(image24);
		Image* image25 = loadBMP("5.bmp");
		_textureId35 = loadTexture(image25);
		Image* image26 = loadBMP("6.bmp");
		_textureId36 = loadTexture(image26);
		Image* image27 = loadBMP("7.bmp");
		_textureId37 = loadTexture(image27);
		Image* image28 = loadBMP("8.bmp");
		_textureId38 = loadTexture(image28);
		Image* image29 = loadBMP("9.bmp");
		_textureId39 = loadTexture(image29);
		Image* image210 = loadBMP("10.bmp");
		_textureId310 = loadTexture(image210);
		Image* image211 = loadBMP("11.bmp");
		_textureId311 = loadTexture(image211);

		Image* image3 = loadBMP("fire.bmp");//wall
		_textureId4 = loadTexture(image3);
		Image* image4 = loadBMP("grass.bmp");//grass
		_textureId5 = loadTexture(image4);
		Image* image5 = loadBMP("wood3.bmp");//grass
		_textureId6 = loadTexture(image5);
		Image* image8 = loadBMP("world.bmp");//grass
		_textureId8 = loadTexture(image8);
		Image* image9 = loadBMP("wall.bmp");//grass
		_textureId9 = loadTexture(image9);
		printf("counter...%d\n");
		delete image;
		delete image1;
		delete image21;
		delete image3;
		delete image4;
		delete image5;
		delete image8;
		delete image9;
		t3dInit();

	}

	// Function called when the window is resized
	void handleResize(int w, int h) {
		/*    glViewport(w/3,0,w/3,h);
		      glMatrixMode(GL_PROJECTION);
		      glLoadIdentity();
		      gluPerspective(45.0f, (float)w / (float)h, 0.1f, 200.0f);
		      glMatrixMode(GL_MODELVIEW);
		//      while(1)
		drawScene();
		//	glutIdleFunc(drawScene);
		glLoadIdentity();
		glViewport(0, 0, w/3, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (float)w / (float)h, 0.1f, 200.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();*/
	}

	void handleKeypress1(unsigned char key, int x, int y) 
	{

		if(key==112)//p pause
		{
			pause1++;
		}
		if (key == 27) 
		{
			cleanup();
			exit(0);     // escape key is pressed
		}
		else if (key == 98) //b, rotating view
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
			if(incr>=1)
			{
				incr++;
			}
			if(incr<1)
			{
				incr+=0.1f;
			}
		}
		if(key==111) //o dec speed of robot
		{
			if(incr>1)
			{
				incr--;
			}
			if(incr<=1)
			{
				incr-=0.1f;
			}
		}
		if(key==117)//u , up(tower) view
		{
			upview++;
		}

		if(key==119)//w tile inc
		{
			t2--;
			if(col22==0)
			{
				col00=0;
				col11=0;
				col22=0;
				col33=0;
				//flagx=0;
				//flagz=-1;
				//printf("flagz:%d\n");
				if(tower%2==1)
				{
					cam_x2 += lx2 * fraction;
					cam_z2 += lz2 * fraction;
				}
				else
				{
					printf("moving up\n");
					pindx2=indx2;
					g2++;
					gtheta2=180;
					indx2=2;
					if(pindx2==0)
					{
						move_x2=-move_x2;
						move_z2=-move_z2;
					}
					else if(pindx2==1)
					{
						intr2=move_z2;
						move_z2=move_x2;
						move_x2=-intr2;
					}
					else if(pindx2==3)
					{
						intr2=move_x2;
						move_x2=move_z2;
						move_z2=-intr2;
					}
					move_z2=move_z2+0.2f*incr;	
					//		move_z+=0.2f;
				}
				//}
		}
	}
	if(key==122)//z
	{
		t2++;
	}
	if(key==115)//s
	{
		t1++;
		if(col00==0)
		{
			col00=0;
			col11=0;
			col22=0;
			col33=0;
			//flagx=0;
			//flagz=1;
			if(tower%2==1)
			{
				cam_x2 -= lx2 * fraction;
				cam_z2 -= lz2 * fraction;
			}
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
				  pindx2=indx2;
				  g2++;
				  gtheta2=0;
				  indx2=0;
				  if(pindx2==1)
				  {
					  intr2=move_x2;
					  move_x2=move_z2;
					  move_z2=-intr2;
				  }
				  else if(pindx2==2)
				  {	
					  move_z2=-move_z2;
					  move_x2=-move_x2;
					  //zco=-zco;
					  //xco=-xco;
				  }
				  else if(pindx2==3)
				  {
					  intr2=move_x2;
					  move_x2=-move_z2;
					  move_z2=intr2;
					  //intr=xco;
					  //xco=-zco;
					  //zco=intr;
				  }
				  move_z2=move_z2+0.2f*incr;	
				  //		move_z+=0.2f;
			  }

		}
		}
		if(key==97)//a //LEFT FOR PLAYER2
		{
			t1--;
			if(col33==0)
			{
				//flagz=0;
				//flagx=-1;
				col00=0;
				col11=0;
				col22=0;
				col33=0;
				if(tower%2==1)
				{
					angle2 -= 0.01f;
					lx2 = sin(angle2);
					lz2 = -cos(angle2);
				}
				/*else if(tower%2==0){
				  if(person%2==1)
				  {
				  down=0;
				  angle1 -= 0.03f;
				  lx = sin(angle1);
				  lz = -cos(angle1);
				  }*/
				  else
				  {
					  pindx2=indx2;
					  g2++;
					  gtheta2=-90;
					  indx2=3;
					  if(pindx2==0)
					  {
						  intr2=move_x2;
						  move_x2=move_z2;
						  move_z2=-intr2;
					  }
					  else if(pindx2==1)
					  {
						  move_x2=-move_x2;
						  move_z2=-move_z2;
					  }
					  else if(pindx2==2)
					  {
						  intr2=move_z2;
						  move_z2=move_x2;
						  move_x2=-intr2;
					  }
					  //move_z+=0.2f;
					  move_z2=move_z2+0.2f*incr;	
				  }
				  //}
			}

		}
		if(key==103)//g helicopter view
		{
			gazeno++;
		}
		/* numpad to handle all the combat operations*/
		if(key == 49) // shoot with gun or fire 
		{
			if(gun == 1)
			{
				press = 1;
				shoot ++;
				if(shoot >= 6)
					shoot = shoot % 5;
			}

		}
		if(key == 100) // d //RIGHT FOR PLAYER 2
		{

			if(col11==0)
			{
				col00=0;
				col11=0;
				col22=0;
				col33=0;
				//flagz=0;
				//flagx=1;
				if(tower%2==1)
				{
					angle2 += 0.01f;
					lx2 = sin(angle2);
					lz2 = -cos(angle2);
				}/*
				    else if(tower%2==0){	
				    if(person%2==1)
				    {
				    down=0;
				    angle1 += 0.03f;
				    lx = sin(angle1);
				    lz = -cos(angle1);
				    }*/
				    else
				    {

					    pindx2=indx2;
					    g2++;
					    gtheta2=90;
					    indx2=1;
					    if(pindx2==0)
					    {
						    intr2=move_z2;
						    move_z2=move_x2;
						    move_x2=-intr2;
					    }
					    else if(pindx2==2)
					    {
						    //printf("up to right..initial x..%f z..%f\n",xco,zco);
						    intr2=move_x2;
						    move_x2=move_z2;
						    move_z2=-intr2;
						    //printf("final x..%f z..%f\n",xco,zco);
					    }
					    else if(pindx2==3)
					    {
						    move_z2=-move_z2;
						    move_x2=-move_x2;
					    }
					    move_z2=move_z2+0.2f*incr;	
					    //move_z+=0.2f;
				    }
				    //}
			}
		}

		if(key==106) //j key for jump
		{
			if(jump==1)
			{
				jump=0;
			}
			else
				jump=1;
		}
		if(key == 109) // m key for multiplayer
		{
			if(multiplay == 1)
			{
				multiplay =0;
			}
			else
				multiplay = 1;
			printf("----------MULTIPLAYER IS = %d ---------- \n",multiplay); 
		}


	}
	void handleKeypress2(int key, int x, int y) 
	{
		//if(win!=1){
		if(pause1%2==0)
		{
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
					    else
					    {

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
					if(tower%2==1)
					{
						cam_x += lx * fraction;
						cam_z += lz * fraction;
					}
					/*else if(tower%2==0){
					  if(person%2==1)
					  {
					  if(down>0){lx=-lx;lz=-lz;}
					  down=0;
					  move_x += lx * fraction;
					  move_z += lz * fraction;}

					 */
					  else
					  {
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
				if(col0==0)
				{
					col0=0;
					col1=0;
					col2=0;
					col3=0;
					//flagx=0;
					//flagz=1;
					if(tower%2==1)
					{
						cam_x -= lx * fraction;
						cam_z -= lz * fraction;
					}
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
		//}
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
