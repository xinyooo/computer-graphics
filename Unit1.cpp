//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLCtrl"
#pragma resource "*.dfm"
#include<stdio.h>
#include<stdlib.h>
#include <cstdio>
using namespace std;
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
FILE* infile;
AnsiString Path;
GLfloat theta[] = {0.0,0.0,0.0};
float xt = 0.0;
float yt = 0.0;
float zt = 0.0;
float xs = 1.0;
float ys = 1.0;
float zs = 1.0;
float tmpx = 1;
float tmpy = 1;
float tmpz = 1;
int color = 0;
int cubeStatus;
int vp = 1;
int pmc = 0;
int materialChoose = 0;

char *fileStr;
int *fcolor;
int *bcolor;
int r;
float *vx;
float *vy;
float *vz;
float *nx;
float *ny;
float *nz;
float xmid;
float ymid;
float zmid;
float cx;
float cy;
float cz;
float mmax = 3.0;

bool BlueLight=false;
bool RedLight=false;
bool GreenLight=false;

GLfloat global_ambient[] = {0.2,0.2,0.2,1.0};

GLfloat light_ambient[][4]={{1.0f,0.0f,0.0f,1.0f},{0.0f,1.0f,0.0f,1.0f},{0.0f,0.0f,1.0f,1.0f},{0.2f,0.2f,0.2f,1.0f}};
GLfloat light_diffuse[][4]={{0.2f,0.3f,0.3f,1.0f}};
GLfloat light_specular[][4]={{0.7f,0.3f,0.3f,1.0f}};

GLfloat emission[]={0.0,0.3,0.3,1.0};
GLfloat m_ambient[][4]={{0.19225,0.19225,0.19225,1.0},{0.24725,0.1995,0.0745,1.0},{0.19125,0.0735,0.0225,1.0}};
GLfloat m_diffuse[][4]={{0.50754,0.50754,0.50754},{0.75164,0.0648,0.22648,1.0},{0.7038,0.27048,0.0828,1.0}};
GLfloat m_specular[][4]={{0.508273,0.508273,0.508273,1.0},{0.628281,0.555802,0.366065,1.0},{0.256777,0.137622,0.086014,1.0}};


GLfloat vertices[8][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0}};
GLfloat colors[8][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0},{1.0,1.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,0.0,1.0},{1.0,1.0,1.0},{0.0,1.0,1.0}};
GLfloat normals[8][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0}};
GLfloat xyzvertices[4][3] = {{0,0,0},{4,0,0},{0,4,0},{0,0,4}};
GLfloat xyzcolor[3][3] = {{1,0,0},{0,1,0},{0,0,1}};

void polygon(int a, int b, int c , int d)
{

/* draw a polygon via list of vertices */

 	glBegin(GL_POLYGON);
		glColor3fv(colors[a]);
		glNormal3fv(normals[a]);
		glVertex3fv(vertices[a]);
		glColor3fv(colors[b]);
		glNormal3fv(normals[b]);
		glVertex3fv(vertices[b]);
		glColor3fv(colors[c]);
		glNormal3fv(normals[c]);
		glVertex3fv(vertices[c]);
		glColor3fv(colors[d]);
		glNormal3fv(normals[d]);
		glVertex3fv(vertices[d]);
	glEnd();
																										}

void colorcube(void)
{

/* map vertices to faces */

	polygon(3,2,1,0);
	polygon(2,3,7,6);
	polygon(7,3,0,4);
	polygon(1,2,6,5);
	polygon(4,5,6,7);
	polygon(5,4,0,1);
}

void TRS(){
        glTranslatef(xt,0.0,0.0);
        glTranslatef(0.0,yt,0.0);
        glTranslatef(0.0,0.0,zt);
        glRotatef(theta[0], 1.0, 0.0, 0.0);
        glRotatef(theta[1], 0.0, 1.0, 0.0);
        glRotatef(theta[2], 0.0, 0.0, 1.0);
        glScalef(xs,ys,zs);
}
void drawModel(){
        int j = 0;
        glBegin(GL_TRIANGLES);
                while(j<r){
                        glColor3ub(fcolor[j*3],fcolor[j*3+1],fcolor[j*3+2]);
                        glNormal3f(nx[j*3],ny[j*3],nz[j*3]);
                        glVertex3f(vx[j*3]-xmid,vy[j*3]-ymid,vz[j*3]-zmid);
                        glNormal3f(nx[j*3+1],ny[j*3+1],nz[j*3+1]);
                        glVertex3f(vx[j*3+1]-xmid,vy[j*3+1]-ymid,vz[j*3+1]-zmid);
                        glNormal3f(nx[j*3+2],ny[j*3+2],nz[j*3+2]);
                        glVertex3f(vx[j*3+2]-xmid,vy[j*3+2]-ymid,vz[j*3+2]-zmid);
                        j++;
                }
        glEnd();
}
void drawxyz(){
        glBegin(GL_LINES);
                glColor3f(1.0,0.0,0.0);
                glVertex3f(0.0,0.0,0.0);
                glVertex3f((mmax*0.6),0.0,0.0);
                glColor3f(0.0,1.0,0.0);
                glVertex3f(0.0,0.0,0.0);
                glVertex3f(0.0,(mmax*0.6),0.0);
                glColor3f(0.0,0.0,1.0);
                glVertex3f(0.0,0.0,0.0);
                glVertex3f(0.0,0.0,(mmax*0.6));
        glEnd();
}
void lights(){
        GLfloat light_position[][4]={{mmax*1,mmax*(-1),0.0f,1.0f},{mmax*1,0.0f,mmax*1,1.0f},{0.0f,mmax*(-1),mmax*1,1.0f}};

        if(BlueLight){
                glLoadIdentity();
                glLightfv(GL_LIGHT2,GL_AMBIENT,light_ambient[2]);
                glLightfv(GL_LIGHT2,GL_DIFFUSE,light_diffuse[0]);
                glLightfv(GL_LIGHT2,GL_SPECULAR,light_specular[0]);
                glLightfv(GL_LIGHT2,GL_POSITION,light_position[2]);
                glEnable(GL_LIGHT2);
        }
        else{
                glDisable(GL_LIGHT2);
        }
        if(GreenLight){
                glLoadIdentity();
                glLightfv(GL_LIGHT1,GL_AMBIENT,light_ambient[1]);
                glLightfv(GL_LIGHT1,GL_DIFFUSE,light_diffuse[0]);
                glLightfv(GL_LIGHT1,GL_SPECULAR,light_specular[0]);
                glLightfv(GL_LIGHT1,GL_POSITION,light_position[1]);
                glEnable(GL_LIGHT1);
        }
        else{
                glDisable(GL_LIGHT1);
        }
        if(RedLight){
                glLoadIdentity();
                glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient[0]);
                glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse[0]);
                glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular[0]);
                glLightfv(GL_LIGHT0,GL_POSITION,light_position[0]);
                glEnable(GL_LIGHT0);
        }
        else{
                glDisable(GL_LIGHT0);
        }
}

void materials(int material){
        if(material==0){
                glMaterialf(GL_FRONT,GL_SHININESS,27.8974);
        }else if(material==2){
                glMaterialf(GL_FRONT,GL_SHININESS,51.2);
        }else{
                glMaterialf(GL_FRONT,GL_SHININESS,9.84615);
        }
        glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,emission);
        glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,m_ambient[materialChoose]);
        glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,m_diffuse[materialChoose]);
        glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,m_specular[materialChoose]);
}

void see(){
        if(pmc==0)
                glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        else
                glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        drawxyz();
        TRS();
        if(color==0){
                glShadeModel(GL_SMOOTH);
                colorcube();
        }else if(color==1){
                glShadeModel(GL_FLAT);
                colorcube();
        }else if(color==2){
                drawModel();
        }
        
}

void __fastcall TForm1::ScrollBar1Change(TObject *Sender)
{
        int k = ScrollBar1->Position;
        Label4->Caption = k;
        xt = (double)k/30*(mmax/120);
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBar2Change(TObject *Sender)
{
        int k = ScrollBar2->Position;
        Label5->Caption = k;
        yt = (double)k/30*(mmax/120);
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBar3Change(TObject *Sender)
{
        int k = ScrollBar3->Position;
        Label6->Caption = k;
        zt = (double)k/30*(mmax/120);
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        ScrollBar1->Position = 0;
        ScrollBar2->Position = 0;
        ScrollBar3->Position = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBar4Change(TObject *Sender)
{
        int k = ScrollBar4->Position;
        Label10->Caption = k;
        theta[0]=k;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBar5Change(TObject *Sender)
{
        int k = ScrollBar5->Position;
        Label11->Caption = k;
        theta[1]=k;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBar6Change(TObject *Sender)
{
        int k = ScrollBar6->Position;
        Label12->Caption = k;
        theta[2]=k;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        theta[0]=0;
        theta[1]=0;
        theta[2]=0;
        ScrollBar4->Position = 0;
        ScrollBar5->Position = 0;
        ScrollBar6->Position = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBar7Change(TObject *Sender)
{
        int k = ScrollBar7->Position;
        Label16->Caption = k;
        xs = (double)k/100;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBar8Change(TObject *Sender)
{
        int k = ScrollBar8->Position;
        Label17->Caption = k;
        ys = (double)k/100;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBar9Change(TObject *Sender)
{
        int k = ScrollBar9->Position;
        Label18->Caption = k;
        zs = (double)k/100;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        xs = 1;
        ys = 1;
        zs = 1;
        tmpx = 1;
        tmpy = 1;
        tmpz = 1;
        ScrollBar7->Position = 100;
        ScrollBar8->Position = 100;
        ScrollBar9->Position = 100;
        ScrollBar10->Position = 100;
        CheckBox1->Checked = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
        if(CheckBox1->Checked==true){
                tmpx = xs;
                tmpy = ys;
                tmpz = zs;
                ScrollBar7->Enabled = false;
                ScrollBar8->Enabled = false;
                ScrollBar9->Enabled = false;
                ScrollBar10->Visible = true;
                Label19->Visible = true;
        }else if(CheckBox1->Checked==false){
                ScrollBar7->Enabled = true;
                ScrollBar8->Enabled = true;
                ScrollBar9->Enabled = true;
                ScrollBar10->Visible = false;
                Label19->Visible = false;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBar10Change(TObject *Sender)
{
        int k = ScrollBar10->Position;
        Label19->Caption = k;
        xs = tmpx*(double)k/100;
        ys = tmpy*(double)k/100;
        zs = tmpz*(double)k/100;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::init(TObject *Sender)
{
        glClearColor(0.5,0.5,0.5,1.0);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_NORMALIZE);
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT,global_ambient);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::display(TObject *Sender)
{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT,global_ambient);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-mmax*1.2,mmax*1.2,-mmax*1.2,mmax*1.2,-5*mmax,5*mmax);
        glMatrixMode(GL_MODELVIEW);
        lights();
        materials(materialChoose);
if(vp==1){
        glLoadIdentity();
        gluLookAt(mmax*1.2,mmax*1.2,mmax*1.2,0.0,0.0,0.0,0.0,1.0,0.0);
        glViewport(0,0,500,500);
        see();
}else if(vp==4){
        glLoadIdentity();
        gluLookAt(0.0,0.0,mmax*1.2,0.0,0.0,0.0,0.0,1.0,0.0);
        glViewport(0,250,250,250);
        see();
        glLoadIdentity();
        gluLookAt(mmax*1.2,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0);
        glViewport(0,0,250,250);
        see();
        glLoadIdentity();
        gluLookAt(mmax*1.2,mmax*1.2,mmax*1.2,0.0,0.0,0.0,0.0,1.0,0.0);
        glViewport(250,250,250,250);
        see();
        glLoadIdentity();
        gluLookAt(0.0,mmax*1.2,0.0,0.0,0.0,0.0,1.0,0.0,0.0);
        glViewport(250,0,250,250);
        see();
}
glFlush();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
        color = 0;
        cubeStatus = 0;
        mmax = 3.0;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
        color = 1;
        cubeStatus = 1;
        mmax = 3.0;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void readData(){
        char ch;
        char cc[50];
        int result;
        float temp1[3];
        float temp2[3];
        int n = 0;
        int i = 0;
        free(fcolor);
        free(bcolor);
        free(vx);
        free(vy);
        free(vz);
        free(nx);
        free(ny);
        free(nz);
        cx = 0;
        cy = 0;
        cz = 0;
        if(infile!=NULL){
                while((ch=fgetc(infile))!=EOF){
                        if(ch=='\n'){
                                n++;
                        }
                }
                fclose(infile);
                r = n/5;
                infile = fopen(Path.c_str(),"r");
                fcolor = (int*)malloc(sizeof(int)*3*r);
                bcolor = (int*)malloc(sizeof(int)*3*r);
                vx = (float*)malloc(sizeof(float)*3*r);
                vy = (float*)malloc(sizeof(float)*3*r);
                vz = (float*)malloc(sizeof(float)*3*r);
                nx = (float*)malloc(sizeof(float)*3*r);
                ny = (float*)malloc(sizeof(float)*3*r);
                nz = (float*)malloc(sizeof(float)*3*r);

                while(fscanf(infile,"%s",cc)!=EOF){
                        if(strstr(cc,"Triangle")!=NULL){
                                fscanf(infile,"%d%d%d%d%d%d",&fcolor[i],&fcolor[i+1],&fcolor[i+2],&bcolor[i],&bcolor[i+1],&bcolor[i+2]);
                                fscanf(infile,"%f%f%f%f%f%f",&vx[i],&vy[i],&vz[i],&nx[i],&ny[i],&nz[i]);
                                fscanf(infile,"%f%f%f%f%f%f",&vx[i+1],&vy[i+1],&vz[i+1],&nx[i+1],&ny[i+1],&nz[i+1]);
                                fscanf(infile,"%f%f%f%f%f%f",&vx[i+2],&vy[i+2],&vz[i+2],&nx[i+2],&ny[i+2],&nz[i+2]);
                        }
                        i = i+3;
                }
                temp1[0] = vx[0];
                temp1[1] = vy[0];
                temp1[2] = vz[0];
                temp2[0] = vx[0];
                temp2[1] = vy[0];
                temp2[2] = vz[0];
                for(int k = 0;k<r;k++){
                        if(temp1[0]<vx[k]){
                                temp1[0] = vx[k];
                        }
                        if(temp1[1]<vy[k]){
                                temp1[1] = vy[k];
                        }
                        if(temp1[2]<vz[k]){
                                temp1[2] = vz[k];
                        }
                        if(temp2[0]>vx[k]){
                                temp2[0] = vx[k];
                        }
                        if(temp2[1]>vy[k]){
                                temp2[1] = vy[k];
                        }
                        if(temp2[2]>vz[k]){
                                temp2[2] = vz[k];
                        }
                }
                xmid = (temp1[0]+temp2[0])/2;
                ymid = (temp1[1]+temp2[1])/2;
                zmid = (temp1[2]+temp2[2])/2;
                cx = temp1[0]-xmid;
                cy = temp1[1]-ymid;
                cz = temp1[2]-zmid;
                if(cy>cx){
                        if(cz>cy){
                                mmax = cz;
                        }else{
                                mmax = cy;
                        }
                }else if(cy<cx){
                        if(cz>cx){
                                mmax = cz;
                        }else{
                                mmax = cx;
                        }
                }
        }
}

void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
        color = 2;
        AnsiString Dir,Name;

	if( OpenDialog1->Execute() )
	{
                Dir = ExtractFileDir(OpenDialog1->FileName);
                Name = ExtractFileName(OpenDialog1->FileName);
                Label20->Caption = Dir+"\\"+Name;
                Path = Dir+"\\"+Name;
                infile = fopen(Path.c_str(),"r");
                readData();
                fclose(infile);
	}else{
                color = cubeStatus;
                mmax = 120;
                Label20->Caption = "";
                if(color==0){
                        RadioButton1->Checked=true;
                }else if(color==1){
                        RadioButton2->Checked=true;
                }

        }
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton5Click(TObject *Sender)
{
        vp=4;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton4Click(TObject *Sender)
{
        vp=1;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox5Click(TObject *Sender)
{
        if(CheckBox5->Checked)
                RedLight = true;
        else
                RedLight = false;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton6Click(TObject *Sender)
{
        materialChoose = 1;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton7Click(TObject *Sender)
{
        materialChoose = 0;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton8Click(TObject *Sender)
{
        materialChoose = 2;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox6Click(TObject *Sender)
{
        if(CheckBox6->Checked)
                GreenLight = true;
        else
                GreenLight = false;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox7Click(TObject *Sender)
{
        if(CheckBox7->Checked)
                BlueLight = true;
        else
                BlueLight = false;
        GLBox1->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton10Click(TObject *Sender)
{
        pmc = 1;
        GLBox1->Invalidate();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton9Click(TObject *Sender)
{
        pmc = 0;
        GLBox1->Invalidate();        
}
//---------------------------------------------------------------------------
