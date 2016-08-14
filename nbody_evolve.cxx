#include <stdlib.h>
//#include <GL/glut.h> 
#include <GL/glut.h> 
#include <GL/freeglut.h> 
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <string>

#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
	   glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();

using std::cin;
using std::pow;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;

void init(void)
{
   GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat position[] = { 0.0, 3.0, 2.0, 0.0 };
   GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
   GLfloat local_view[] = { 0.0 };

   glClearColor(0.0, 0.0, 0.0, 0.0);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_SMOOTH);

   glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
   glLightfv(GL_LIGHT0, GL_POSITION, position);
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
   glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
  
}

ifstream& open_file(ifstream &in, const string &file)
{
	in.close(); //close in case it was already open
	in.clear(); // clear any existing errors
	// ifthe open failsk the stream will bi in an invalid state
	in.open(file.c_str()); //open the file we were given
	return in; // condition state is good if open succeed
}



/*void DrawText(GLint x, GLint y, char* s, GLfloat r, GLfloat g, GLfloat b)
{
    int lines;
    char* p;

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, glutGet(GLUT_WINDOW_WIDTH), 
	    0.0, glutGet(GLUT_WINDOW_HEIGHT), -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glColor3f(r,g,b);
    glRasterPos2i(x, y);
    for(p = s, lines = 0; *p; p++) {
      	  if (*p == '\n') {
  	      lines++;
     	      glRasterPos2i(x, y-(lines*18));
      	  }
 	  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
        }
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
      glPopMatrix();
      glMatrixMode(GL_MODELVIEW);
}
*/


void display(void)
{
//   GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
   GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
   GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat no_shininess[] = { 0.0 };
   GLfloat low_shininess[] = { 5.0 };
   GLfloat high_shininess[] = { 100.0 };

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glLoadIdentity();
   /* In the default position, the carema is at the origin, is looking 
    * down the negative z-axis, and has the positive y-axis as straight
    * up. This is the same as calling
    * gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 1.0, 0.0);
    * gluLookAt(<GLdouble>eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz)
    * */
   //gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 1.0, 0.0);
   gluLookAt(0.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

   vector<string> filelist; 
	string fnumstring, filename;
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
	filelist.push_back("1.txt");
   for (int fnum = 1; fnum < 19461; fnum=fnum+10) {
	std::stringstream out;
	out << fnum;
	fnumstring = out.str();
	filename = fnumstring + ".txt";
	filelist.push_back(filename);
      }
	filelist.push_back("19461.txt");
	filelist.push_back("19461.txt");
	filelist.push_back("19461.txt");
	filelist.push_back("19461.txt");
	filelist.push_back("19461.txt");
	filelist.push_back("19461.txt");
	filelist.push_back("19461.txt");
	filelist.push_back("19461.txt");
	filelist.push_back("19461.txt");

	ifstream infile;
	vector<string>::const_iterator it = filelist.begin();
	while (it != filelist.end())
	{
		open_file(infile, it->c_str());
		string line;
		vector<float> avec, evec, ivec, mvec; // a, e, i, m
		float  i, j, k, q, w, u, z, g;
		while (getline(infile, line)) {
			istringstream stream(line);
			while (stream >> q >> i >> j >> w >> u >> z >> g >> k); {
				avec.push_back(i);
				evec.push_back(j);
				ivec.push_back(w);
				mvec.push_back(k);
			}
		}
		infile.close();

		for (vector<float>::const_iterator ater = avec.begin(), eter = evec.begin(), iter = ivec.begin(), mter = mvec.begin(); ater != avec.end(); ++ater, ++eter, ++iter, ++mter) {
			glPushMatrix();
       		   //color
			GLfloat no_mat[] = {0.2, pow(*mter,0.3333)*99, 0.2, 0.3};
			// position
   	  	   glTranslatef (*ater*4.0-5.0, *eter*12.5-2.5, 0.0); //x(-5,5), y(-4,4), z
		   glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
		   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		   glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
		   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat); 
		   glutSolidSphere(pow(*mter,0.3333)*22, 16, 16); // radius, roundness, roundness
		   glPopMatrix(); 
		}

//		glScalef(0.003,0.003,1);
//		glutStrokeString(GLUT_STROKE_ROMAN, (unsigned char*)"some text");


		 glRasterPos2f (-0.7, -4.05);
		  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'a');
		 glRasterPos2f (-0.3, -4.05);
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '(');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ')');
		 glRasterPos2f (-5.07, -3.5);
		drawOneLine(-3.0, -3.0, -3.0, -2.85); //0.5
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 glRasterPos2f (-1.07, -3.5);
		drawOneLine(-1.0, -3.0, -1.0, -2.8); //1.0
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
		 glRasterPos2f (2.93, -3.5);
		drawOneLine(1.0, -3.0, 1.0, -2.85); //1.5
		drawOneLine(3.0, -3.0, 3.0, -2.8); //2.0
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '2');

		 glRasterPos2f (-3.1, -3.5);
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '.');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '5');
		 glRasterPos2f (0.9, -3.5);
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '.');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '5');

		 glRasterPos2f (-5.72,  1.1);
		  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'e');
		 drawOneLine(-4.85, 5.0, -5.0, 5.0);
		 glRasterPos2f (-5.45,  4.9);
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '.');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '6');
		 drawOneLine(-4.85, 2.5, -5.0, 2.5);
		 glRasterPos2f (-5.45,  2.4);
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '.');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '4');
		 drawOneLine(-4.85, 0.0, -5.0, 0.0);
		 glRasterPos2f (-5.45,  -0.1);
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '.');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '2');
		 drawOneLine(-4.85, -2.5, -5.0, -2.5);
		 glRasterPos2f (-5.45,  -2.6);
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '.');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 drawOneLine(-4.9, 3.75, -5.0, 3.75);
		 drawOneLine(-4.9, 1.25, -5.0, 1.25);
		 drawOneLine(-4.9, -1.25, -5.0, -1.25);

		drawOneLine(-5.0, -3.0, -5.0, 5.8);
		drawOneLine(-5.0, -3.0, 3.8, -3.0);
	   glFlush();
	  glutSwapBuffers();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	  ++it;
	}
}

void idle()
 {
     glutPostRedisplay();
 }


void reshape(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= (h * 2))
      glOrtho (-6.0, 6.0, -3.0*((GLfloat)h*2)/(GLfloat)w, 
         3.0*((GLfloat)h*2)/(GLfloat)w, -10.0, 10.0);
   else
      glOrtho (-6.0*(GLfloat)w/((GLfloat)h*2), 
         6.0*(GLfloat)w/((GLfloat)h*2), -3.0, 3.0, -10.0, 10.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 'y':
         exit(0);
         break;
   }
}

void mouse(int button, int state, int x, int y) 
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(idle);
         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (900, 700);
   glutCreateWindow("hello"); //argv[0]);
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc (keyboard);
   glutMouseFunc(mouse);
   glutMainLoop();
   return 0; 
}
