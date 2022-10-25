object Form1: TForm1
  Left = 364
  Top = 177
  BorderStyle = bsDialog
  Caption = 'Крестики нолики'
  ClientHeight = 300
  ClientWidth = 300
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PopupMenu = PopupMenu1
  OnMouseDown = FormMouseDown
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object PopupMenu1: TPopupMenu
    object N1: TMenuItem
      Caption = 'Новая игра'
      OnClick = N1Click
    end
  end
end
