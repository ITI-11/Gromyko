Dim s, FSO, F, Code1, Path, a 

do
	Set FSO = WScript.CreateObject("Scripting.FileSystemObject")
	Set WshShell = WScript.CreateObject("WScript.Shell")

	WScript.StdOut.WriteLine "����:"
	WScript.StdOut.WriteLine "---------------------"
	WScript.StdOut.WriteLine "1. ���������� �� ������."
	WScript.StdOut.WriteLine "2. ����������� �������� ������ �� ����� � E:\BackUp."
	WScript.StdOut.WriteLine "3. ����� �� ����� ���� � ��������� ����������� �����."
	WScript.StdOut.WriteLine "4. �����."
	WScript.StdOut.Write "�������� ����� ����:"
	s=WScript.StdIn.ReadLine
	'....
	if(s="1") Then
		WScript.StdOut.WriteLine "�����: ������� ���� ������������, ���-11"

	elseif(s="2") Then
		WScript.StdOut.Write "������� ���������� ������:"
		a=WScript.StdIn.ReadLine
		

		
		Code1=WshShell.Run ("%COMSPEC% /c 02.cmd>"+a,0,true)

		
	
	elseif(s="3") Then
		WScript.StdOut.Write "������� ����������� �����:"
		a=WScript.StdIn.ReadLine
		
		Set WshFldrs = WshShell.SpecialFolders
		WScript.Echo(a + " = " + WshFldrs.item(a))

	End if

loop until (s="4")
