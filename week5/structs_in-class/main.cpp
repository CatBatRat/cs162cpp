#include <iostream>

using namespace std;

struct Link {
    int test;
    Link * next;
    Link * previous;
};

Link * addHead( Link * head, int value );
void display( Link * head );
bool findItem( Link * head, int value );
int getHead( Link * head );
bool isEmpty( Link * head );

int main() {

    Link * head = nullptr;

    for( int i=0; i< 6; i++ )
    {
        head = addHead( head, i );
    }
    display( head );
    int input = 0;
    cout << "Input the number to search for." << endl;
    cin >> input;
    if( findItem( head, input ) )
        cout << "Found the value." << endl;
    else
        cout << "That value is not in the list." << endl;
    cout << getHead( head ) << endl;


    return 0;
}

Link * addHead( Link * head, int value )
{
    Link * temp = new Link;
    temp->test = value;
    temp->next = head;
    temp->previous = head;
    head = temp;
    return head;
}

void display( Link * head )
{
    Link * show = head;
    while(show)
    {
        cout << show->test << endl;
        show = show->next;
    }
}

bool findItem( Link * head, int value )
{
    bool result = false;
    Link * sch = head;
    while(sch)
    {
        if( sch->test == value )
        {
            result = true;
        }
        sch = sch->next;
    }
    return result;
}

int getHead( Link * head )
{
    return head->test;
}

bool isEmpty( Link * head )
{
    return (head)?true:false;
}
