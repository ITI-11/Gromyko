Dim s, FSO, F, Code1, Path, a 

do
	Set FSO = WScript.CreateObject("Scripting.FileSystemObject")
	Set WshShell = WScript.CreateObject("WScript.Shell")

	WScript.StdOut.WriteLine "МЕНЮ:"
	WScript.StdOut.WriteLine "---------------------"
	WScript.StdOut.WriteLine "1. ИНФОРМАЦИЯ ОБ АВТОРЕ."
	WScript.StdOut.WriteLine "2. КОПИРОВАНИЕ ЗАДАННЫХ ФАЙЛОВ ИЗ ПАПКИ в E:\BackUp."
	WScript.StdOut.WriteLine "3. ВЫВОД НА ЭКРАН ПУТИ К УКАЗАННОЙ СПЕЦИАЛЬНОЙ ПАПКЕ."
	WScript.StdOut.WriteLine "4. ВЫХОД."
	WScript.StdOut.Write "Выберите пункт меню:"
	s=WScript.StdIn.ReadLine
	'....
	if(s="1") Then
		WScript.StdOut.WriteLine "Автор: Громыко Иван Владимирович, ИТИ-11"

	elseif(s="2") Then
		WScript.StdOut.Write "Введите расширение файлов:"
		a=WScript.StdIn.ReadLine
		

		
		Code1=WshShell.Run ("%COMSPEC% /c 02.cmd>"+a,0,true)

		
	
	elseif(s="3") Then
		WScript.StdOut.Write "Введите специальную папку:"
		a=WScript.StdIn.ReadLine
		
		Set WshFldrs = WshShell.SpecialFolders
		WScript.Echo(a + " = " + WshFldrs.item(a))

	End if

loop until (s="4")
