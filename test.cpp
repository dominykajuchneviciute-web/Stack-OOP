#include "stack.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using namespace MySpace;

void log(ofstream &out, const string &msg)
{
    cout << msg << endl;
    out << msg << endl;
}

void printResult(ofstream &out, const string &test, bool pass)
{
    string result = test + ": " + (pass ? "PASS" : "FAIL");
    log(out, result);
}

int main()
{
    try
    {
        ofstream file("log.txt");
        Stack s;
        s.add(1);
        s.add(2);
        s.add(3);
        printResult(file, "Add elements (1,2,3)", s.toString() == "3 2 1 ");
        printResult(file, "View top element", s.view() == 3);
        s += 4;
        printResult(file, "Operator += (add 4)", s.view() == 4);
        s.edit(2, 20);
        printResult(file, "Edit 2 -> 20", s[20] != -1);
        s *= 2;
        printResult(file, "Multiply all by 2", s.view() == 8);
        printResult(file, "Find index of 40", s[40] != -1);
        int removed = s.del();
        printResult(file, "Delete top element", removed == 8);
        s -= 40;
        printResult(file, "Remove value 40", s[40] == -1);
        Stack s2(s);
        printResult(file, "Copy constructor", s == s2);
        Stack s3;
        s3 = s;
        printResult(file, "Assignment operator", s3 == s);
        s3.add(999);
        printResult(file, "Operator <", s < s3);
        printResult(file, "Operator >", s3 > s);
        printResult(file, "Operator ==", !(s == s3));
        printResult(file, "Operator !=", s != s3);
        !s;
        bool isEmpty = true;
        try
        {
            s.view();
            isEmpty = false;
        }
        catch (...)
        {
            isEmpty = true;
        }
        printResult(file, "Clear stack (! operator)", isEmpty);
        bool exceptionThrown = false;
        try
        {
            s.del();
        }
        catch(...)
        {
            exceptionThrown = true;
        }
        printResult(file, "Exception on delete empty", exceptionThrown);
        Stack extra;
        for(int i = 0; i < 10; i++)
            extra.add(i);
        log(file, "Extra stack: " + extra.toString());
        extra *= 3;
        log(file, "After *=3: " + extra.toString());
        extra.edit(27, 999);
        log(file, "After edit: " + extra.toString());
        for(int i = 0; i < 5; i++)
            extra.del();
        log(file, "After deleting 5 elements: " + extra.toString());
        Stack extra2;
        for(int i = 1; i <= 10; i++)
        {
            extra2.add(i);
            log(file, "Added: " + to_string(i));
        }
        log(file, "Extra stack: " + extra2.toString());
        for(int i = 1; i <= 10; i++)
        {
            int index = extra2[i];
            log(file, "Index of " + to_string(i) + ": " + to_string(index));
        }
        extra2 *= 5;
        log(file, "After *=5: " + extra2.toString());
        try
        {
            extra2.edit(25, 250);
            extra2.edit(50, 500);
            log(file, "Edited values (25->250, 50->500)");
        }
        catch(...)
        {
            log(file, "Edit failed unexpectedly");
        }
        log(file, "After edits: " + extra2.toString());
        try
        {
            extra2 -= 250;
            log(file, "Removed 250");
        }
        catch(...)
        {
            log(file, "Failed to remove 250");
        }
        try
        {
            extra2 -= 500;
            log(file, "Removed 500");
        }
        catch(...)
        {
            log(file, "Failed to remove 500");
        }
        log(file, "After removals: " + extra2.toString());
        for(int i = 0; i < 5; i++)
        {
            try
            {
                int v = extra2.del();
                log(file, "Deleted: " + to_string(v));
            }
            catch(...)
            {
                log(file, "Delete failed unexpectedly");
            }
        }
        log(file, "After multiple deletions: " + extra2.toString());
        Stack another;
        another.add(1);
        another.add(2);
        printResult(file, "Extra > another", extra2 > another);
        printResult(file, "Extra < another", extra2 < another);
        !extra2;
        log(file, "Stack cleared");
        bool empty2 = false;
        try
        {
            extra2.view();
        }
        catch (...)
        {
            empty2 = true;
        }
        printResult(file, "Stack empty after clear", empty2);
        file.close();
    }
    catch(...)
    {

    }
    return 0;
}
