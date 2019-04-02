object Form1: TForm1
  Left = 164
  Top = 86
  Width = 1181
  Height = 678
  Caption = 'Final'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label20: TLabel
    Left = 24
    Top = 8
    Width = 3
    Height = 13
  end
  object GLBox1: TGLBox
    Left = 16
    Top = 72
    Width = 500
    Height = 500
    OnGLInit = init
    OnGLDraw = display
  end
  object GroupBox1: TGroupBox
    Left = 528
    Top = 16
    Width = 355
    Height = 155
    Caption = #24179#31227
    TabOrder = 1
    object Label1: TLabel
      Left = 8
      Top = 32
      Width = 7
      Height = 20
      Caption = 'x'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 8
      Top = 72
      Width = 7
      Height = 20
      Caption = 'y'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 8
      Top = 112
      Width = 8
      Height = 20
      Caption = 'z'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 248
      Top = 32
      Width = 9
      Height = 20
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 248
      Top = 72
      Width = 9
      Height = 20
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 248
      Top = 112
      Width = 9
      Height = 20
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ScrollBar1: TScrollBar
      Left = 24
      Top = 32
      Width = 209
      Height = 25
      Min = -100
      PageSize = 0
      TabOrder = 0
      OnChange = ScrollBar1Change
    end
    object ScrollBar2: TScrollBar
      Left = 24
      Top = 72
      Width = 209
      Height = 25
      Min = -100
      PageSize = 0
      TabOrder = 1
      OnChange = ScrollBar2Change
    end
    object ScrollBar3: TScrollBar
      Left = 24
      Top = 112
      Width = 209
      Height = 25
      Min = -100
      PageSize = 0
      TabOrder = 2
      OnChange = ScrollBar3Change
    end
    object Button1: TButton
      Left = 280
      Top = 56
      Width = 50
      Height = 50
      Caption = 'Reset'
      TabOrder = 3
      OnClick = Button1Click
    end
  end
  object GroupBox2: TGroupBox
    Left = 528
    Top = 184
    Width = 355
    Height = 155
    Caption = #26059#36681
    TabOrder = 2
    object Label7: TLabel
      Left = 8
      Top = 32
      Width = 7
      Height = 20
      Caption = 'x'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label8: TLabel
      Left = 8
      Top = 72
      Width = 7
      Height = 20
      Caption = 'y'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label9: TLabel
      Left = 8
      Top = 112
      Width = 8
      Height = 20
      Caption = 'z'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label10: TLabel
      Left = 248
      Top = 32
      Width = 9
      Height = 20
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label11: TLabel
      Left = 248
      Top = 72
      Width = 9
      Height = 20
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label12: TLabel
      Left = 248
      Top = 112
      Width = 9
      Height = 20
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ScrollBar4: TScrollBar
      Left = 24
      Top = 32
      Width = 209
      Height = 25
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 0
      OnChange = ScrollBar4Change
    end
    object ScrollBar5: TScrollBar
      Left = 24
      Top = 72
      Width = 209
      Height = 25
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 1
      OnChange = ScrollBar5Change
    end
    object ScrollBar6: TScrollBar
      Left = 24
      Top = 112
      Width = 209
      Height = 25
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 2
      OnChange = ScrollBar6Change
    end
    object Button2: TButton
      Left = 280
      Top = 56
      Width = 50
      Height = 50
      Caption = 'Reset'
      TabOrder = 3
      OnClick = Button2Click
    end
  end
  object GroupBox3: TGroupBox
    Left = 528
    Top = 352
    Width = 355
    Height = 193
    Caption = #32302#25918
    TabOrder = 3
    object Label13: TLabel
      Left = 8
      Top = 32
      Width = 7
      Height = 20
      Caption = 'x'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label14: TLabel
      Left = 8
      Top = 72
      Width = 7
      Height = 20
      Caption = 'y'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label15: TLabel
      Left = 8
      Top = 112
      Width = 8
      Height = 20
      Caption = 'z'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label16: TLabel
      Left = 248
      Top = 32
      Width = 27
      Height = 20
      Caption = '100'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label17: TLabel
      Left = 248
      Top = 72
      Width = 27
      Height = 20
      Caption = '100'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label18: TLabel
      Left = 248
      Top = 112
      Width = 27
      Height = 20
      Caption = '100'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label19: TLabel
      Left = 312
      Top = 152
      Width = 27
      Height = 20
      Caption = '100'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      Visible = False
    end
    object ScrollBar7: TScrollBar
      Left = 24
      Top = 32
      Width = 209
      Height = 25
      Max = 200
      Min = -100
      PageSize = 0
      Position = 100
      TabOrder = 0
      OnChange = ScrollBar7Change
    end
    object ScrollBar8: TScrollBar
      Left = 24
      Top = 72
      Width = 209
      Height = 25
      Max = 200
      Min = -100
      PageSize = 0
      Position = 100
      TabOrder = 1
      OnChange = ScrollBar8Change
    end
    object ScrollBar9: TScrollBar
      Left = 24
      Top = 112
      Width = 209
      Height = 25
      Max = 200
      Min = -100
      PageSize = 0
      Position = 100
      TabOrder = 2
      OnChange = ScrollBar9Change
    end
    object Button3: TButton
      Left = 280
      Top = 56
      Width = 50
      Height = 50
      Caption = 'Reset'
      TabOrder = 3
      OnClick = Button3Click
    end
    object CheckBox1: TCheckBox
      Left = 24
      Top = 152
      Width = 97
      Height = 25
      Caption = #31561#27604#20363#32302#25918
      TabOrder = 4
      OnClick = CheckBox1Click
    end
    object ScrollBar10: TScrollBar
      Left = 128
      Top = 152
      Width = 169
      Height = 25
      Max = 200
      Min = -100
      PageSize = 0
      Position = 100
      TabOrder = 5
      Visible = False
      OnChange = ScrollBar10Change
    end
  end
  object GroupBox4: TGroupBox
    Left = 904
    Top = 16
    Width = 225
    Height = 153
    TabOrder = 4
    object RadioButton1: TRadioButton
      Left = 24
      Top = 24
      Width = 177
      Height = 25
      Caption = #24425#33394#31435#26041#39636'(SMOOTH)'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 24
      Top = 64
      Width = 177
      Height = 25
      Caption = #19977#33394#31435#26041#39636'(FLAT)'
      TabOrder = 1
      OnClick = RadioButton2Click
    end
    object RadioButton3: TRadioButton
      Left = 24
      Top = 104
      Width = 177
      Height = 25
      Caption = #36617#20837#36039#26009
      TabOrder = 2
      OnClick = RadioButton3Click
    end
  end
  object GroupBox5: TGroupBox
    Left = 904
    Top = 184
    Width = 225
    Height = 81
    Caption = #35222#40670
    TabOrder = 5
    object RadioButton4: TRadioButton
      Left = 24
      Top = 16
      Width = 169
      Height = 25
      Caption = #19968#20491#35222#40670
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadioButton4Click
    end
    object RadioButton5: TRadioButton
      Left = 24
      Top = 48
      Width = 169
      Height = 25
      Caption = #22235#20491#35222#40670
      TabOrder = 1
      OnClick = RadioButton5Click
    end
  end
  object GroupBox6: TGroupBox
    Left = 904
    Top = 280
    Width = 225
    Height = 121
    Caption = #26448#36074
    TabOrder = 6
    object RadioButton6: TRadioButton
      Left = 24
      Top = 24
      Width = 129
      Height = 17
      Caption = #37329
      TabOrder = 0
      OnClick = RadioButton6Click
    end
    object RadioButton7: TRadioButton
      Left = 24
      Top = 56
      Width = 129
      Height = 17
      Caption = #37504
      TabOrder = 1
      OnClick = RadioButton7Click
    end
    object RadioButton8: TRadioButton
      Left = 24
      Top = 88
      Width = 129
      Height = 17
      Caption = #37509
      TabOrder = 2
      OnClick = RadioButton8Click
    end
  end
  object GroupBox7: TGroupBox
    Left = 904
    Top = 416
    Width = 225
    Height = 129
    Caption = #20809#28304
    TabOrder = 7
    object CheckBox5: TCheckBox
      Left = 24
      Top = 32
      Width = 105
      Height = 17
      Caption = #32005#20809
      TabOrder = 0
      OnClick = CheckBox5Click
    end
    object CheckBox6: TCheckBox
      Left = 24
      Top = 64
      Width = 105
      Height = 17
      Caption = #32160#20809
      TabOrder = 1
      OnClick = CheckBox6Click
    end
    object CheckBox7: TCheckBox
      Left = 24
      Top = 96
      Width = 105
      Height = 17
      Caption = #34253#20809
      TabOrder = 2
      OnClick = CheckBox7Click
    end
  end
  object GroupBox8: TGroupBox
    Left = 528
    Top = 560
    Width = 601
    Height = 65
    Caption = 'ShadeModel'
    TabOrder = 8
    object RadioButton9: TRadioButton
      Left = 152
      Top = 24
      Width = 145
      Height = 25
      Caption = 'FILL'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadioButton9Click
    end
    object RadioButton10: TRadioButton
      Left = 352
      Top = 24
      Width = 145
      Height = 25
      Caption = 'LINE'
      TabOrder = 1
      OnClick = RadioButton10Click
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 1096
    Top = 40
  end
end
