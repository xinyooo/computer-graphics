//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "GLCtrl.h"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGLBox *GLBox1;
        TGroupBox *GroupBox1;
        TScrollBar *ScrollBar1;
        TScrollBar *ScrollBar2;
        TScrollBar *ScrollBar3;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TButton *Button1;
        TGroupBox *GroupBox2;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TScrollBar *ScrollBar4;
        TScrollBar *ScrollBar5;
        TScrollBar *ScrollBar6;
        TButton *Button2;
        TGroupBox *GroupBox3;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label18;
        TScrollBar *ScrollBar7;
        TScrollBar *ScrollBar8;
        TScrollBar *ScrollBar9;
        TButton *Button3;
        TCheckBox *CheckBox1;
        TScrollBar *ScrollBar10;
        TLabel *Label19;
        TGroupBox *GroupBox4;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton3;
        TOpenDialog *OpenDialog1;
        TGroupBox *GroupBox5;
        TRadioButton *RadioButton4;
        TRadioButton *RadioButton5;
        TLabel *Label20;
        TGroupBox *GroupBox6;
        TGroupBox *GroupBox7;
        TCheckBox *CheckBox5;
        TCheckBox *CheckBox6;
        TCheckBox *CheckBox7;
        TRadioButton *RadioButton6;
        TRadioButton *RadioButton7;
        TRadioButton *RadioButton8;
        TGroupBox *GroupBox8;
        TRadioButton *RadioButton9;
        TRadioButton *RadioButton10;
        void __fastcall ScrollBar1Change(TObject *Sender);
        void __fastcall ScrollBar2Change(TObject *Sender);
        void __fastcall ScrollBar3Change(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ScrollBar4Change(TObject *Sender);
        void __fastcall ScrollBar5Change(TObject *Sender);
        void __fastcall ScrollBar6Change(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ScrollBar7Change(TObject *Sender);
        void __fastcall ScrollBar8Change(TObject *Sender);
        void __fastcall ScrollBar9Change(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall ScrollBar10Change(TObject *Sender);
        void __fastcall init(TObject *Sender);
        void __fastcall display(TObject *Sender);
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
        void __fastcall RadioButton3Click(TObject *Sender);
        void __fastcall RadioButton5Click(TObject *Sender);
        void __fastcall RadioButton4Click(TObject *Sender);
        void __fastcall CheckBox5Click(TObject *Sender);
        void __fastcall CheckBox2Click(TObject *Sender);
        void __fastcall RadioButton6Click(TObject *Sender);
        void __fastcall RadioButton7Click(TObject *Sender);
        void __fastcall RadioButton8Click(TObject *Sender);
        void __fastcall CheckBox6Click(TObject *Sender);
        void __fastcall CheckBox7Click(TObject *Sender);
        void __fastcall RadioButton10Click(TObject *Sender);
        void __fastcall RadioButton9Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
