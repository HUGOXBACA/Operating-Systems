#include <iostream>
#include <unistd.h>

using namespace std;

int main ()
{
    pid_t childPid = 0;
    int x = 0;

    childPid = fork ();
    if (childPid == -1)
    {
        cout << "Process "<< getpid () << "failed to fork!" ;
	cout << endl;
        return 1;
    }

    if (childPid == 0)
    {
        x = 2;
        cout << "I am the child ";
    }
    else
    {
        x = 1;
        cout << "I am the parent ";
    }
    cout << getpid ();
    cout << endl;
    cout << " my parent is " << getppid ();
    cout << " and my x is " << x;
	cout << endl;

    return 0;
}
