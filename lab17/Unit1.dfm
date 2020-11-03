object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 491
  ClientWidth = 760
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 0
    Top = 0
    Width = 760
    Height = 73
    Align = alTop
    ExplicitLeft = -8
    ExplicitTop = 8
  end
  object Memo1: TMemo
    Left = 0
    Top = 112
    Width = 761
    Height = 377
    TabOrder = 0
  end
  object Button1: TButton
    Left = 288
    Top = 25
    Width = 75
    Height = 25
    Caption = 'Save'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 401
    Top = 25
    Width = 75
    Height = 25
    Caption = 'Save as'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 520
    Top = 25
    Width = 75
    Height = 25
    Caption = 'Open'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 632
    Top = 25
    Width = 75
    Height = 25
    Caption = 'Close'
    TabOrder = 4
    OnClick = Button4Click
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = 'txt'
    Filter = 'Text files|*.txt|All files|*.*'
    Options = [ofHideReadOnly, ofFileMustExist, ofNoReadOnlyReturn, ofEnableSizing]
    Title = 'Open file'
    Left = 40
    Top = 16
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'txt'
    Filter = 'Text file|*.txt|All files|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofNoReadOnlyReturn, ofEnableSizing]
    Title = 'Save file'
    Left = 144
    Top = 16
  end
end
