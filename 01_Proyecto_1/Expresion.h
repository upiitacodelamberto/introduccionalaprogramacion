/**expresion.h
 */

struct Box;		/* declaracion anticipada */

/** Clase sin secciones privadas */
struct Expresion{
	Box *BoxOp1,*BoxOp2,*BoxResult;
	Box *BoxOperador;
	static Box BoxIgual;
	
	/*enum enumAlturaMax*/
	static COORD COORD_C;/* posicion del cursor cuando se inicia y "durante" la impresion de la Expresion */
	Expresion(Box *Op1,Box *Operador,Box *Op2,Box *Result);	/* constructor */
	friend ostream& operator<<(ostream& ostreamOut,Expresion& Expresion2P);	/* funcion amiga *//* ?? */
	void print();
};//end class Expresion

struct Box{
	int intLongDBase;		/* atributo calculado */
	int intLongDAltura;		/* atributo calculado */
	
};//end class Box


//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

	

As per the documentation for the SetConsoleCursorPosition function:

    To determine the current position of the cursor, use the GetConsoleScreenBufferInfo function.

In general, if you know how to get or set something, the MSDN documentation for that function will 
hint at how to do the opposite. That is certainly true in this case.

If we look up the GetConsoleScreenBufferInfo function, we see that we've struck paydirt. It fills 
in a CONSOLE_SCREEN_BUFFER_INFO structure that, among other things, contains a COORD structure that 
indicates the current column and row coordinates of the cursor.

There is even an example. Package it up into a function if you want to make it convenient:

COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
    {
        return cbsi.dwCursorPosition;
    }
    else
    {
        // The function failed. Call GetLastError() for details.
        COORD invalid = { 0, 0 };
        return invalid;
    }
}


As Michael mentioned already in a comment, GetCursorPos doesn't work because it is for the mouse 
cursor (the arrow), not the cursor (insertion point) in a console window. It is returning valid 
values, just not the values you are looking for. Lucky that the return types are different, 
otherwise they'd be easy to mix up. Calling it the "cursor" for a console window is sort of 
misleading, it probably should be called the caret


https://docs.microsoft.com/en-us/windows/console/console-handles

Console Handles
2017-7-12
A console process uses handles to access the input and screen buffers of its console. A process 
can use the GetStdHandle, CreateFile, or CreateConsoleScreenBuffer function to open one of these 
handles.

The GetStdHandle function provides a mechanism for retrieving the standard input (STDIN), 
standard output (STDOUT), and standard error (STDERR) handles associated with a process. During 
console creation, the system creates these handles. Initially, STDIN is a handle to the console's 
input buffer, and STDOUT and STDERR are handles of the console's active screen buffer. However, the 
SetStdHandle function can redirect the standard handles by changing the handle associated with STDIN, 
STDOUT, or STDERR. Because the parent's standard handles are inherited by any child process, subsequent 
calls to GetStdHandle return the redirected handle. A handle returned by GetStdHandle may, therefore, 
refer to something other than console I/O. For example, before creating a child process, a parent 
process can use SetStdHandle to set a pipe handle to be the STDIN handle that is inherited by the 
child process. When the child process calls GetStdHandle, it gets the pipe handle. This means that 
the parent process can control the standard handles of the child process. The handles returned by 
GetStdHandle have GENERIC_READ | GENERIC_WRITE access unless SetStdHandle has been used to set the 
standard handle to have lesser access.


The value of the handles returned by GetStdHandle are not 0, 1, and 2, so the standard predefined 
stream constants in Stdio.h (STDIN, STDOUT, and STDERR) cannot be used in functions that require a 
console handle.

The CreateFile function enables a process to get a handle to its console's input buffer and active 
screen buffer, even if STDIN and STDOUT have been redirected. To open a handle to a console's input 
buffer, specify the CONIN$ value in a call to CreateFile. Specify the CONOUT$ value in a call to 
CreateFile to open a handle to a console's active screen buffer. CreateFile enables you to specify 
the read/write access of the handle that it returns.


The CreateConsoleScreenBuffer function creates a new screen buffer and returns a handle. This handle
can be used in any function that accepts a handle to console output. The new screen buffer is not 
active until its handle is specified in a call to the SetConsoleActiveScreenBuffer function. Note that 
changing the active screen buffer does not affect the handle returned by GetStdHandle. Similarly, using 
SetStdHandle to change the STDOUT handle does not affect the active screen buffer.

Console handles returned by CreateFile and CreateConsoleScreenBuffer can be used in any of the console 
functions that require a handle to a console's input buffer or of a console screen buffer. Handles 
returned by GetStdHandle can be used by the console functions if they have not been redirected to refer 
to something other than console I/O. If a standard handle has been redirected to refer to a file or a 
pipe, however, the handle can only be used by the ReadFile and WriteFile functions.

A process can use the DuplicateHandle function to create a duplicate console handle that has different 
access or inheritability from the original handle. Note, however, that a process can create a duplicate 
console handle only for its own use. This differs from other handle types (such as file, pipe, or mutex 
objects), for which DuplicateHandle can create a duplicate that is valid for a different process.

To close a console handle, a process can use the CloseHandle function
