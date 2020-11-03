unit Unit1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.ExtCtrls;

type
  TForm1 = class(TForm)
    Bevel1: TBevel;
    Memo1: TMemo;
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    OpenDialog1: TOpenDialog;
    SaveDialog1: TSaveDialog;
    procedure Button4Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.Button1Click(Sender: TObject);
begin
  if SaveDialog1.FileName = '' then
    Button2Click(Sender)
  else
    Memo1.Lines.SaveToFile(SaveDialog1.FileName);
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  with SaveDialog1 do
  begin
    if Execute then
      begin
        Memo1.Lines.SaveToFile(FileName);
        Caption := 'My Editor - ' + ExtractFileName(FileName);
      end;
  end;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
  with OpenDialog1 do
  begin
    if Execute then
    begin
      Memo1.Lines.LoadFromFile(FileName);
      HistoryList.Add(FileName);
      Caption := 'My editor - ' + ExtractFileName(FileName);
      SaveDialog1.FileName := FileName;
      FileName := '';
    end;
  end;
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
  Close();
end;

end.
