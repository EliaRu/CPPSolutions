/*
    First the program sorts the input array in descending order of
    the number of people taller than a given person in front
    of him. Then it check if for each person there are enough
    people in front of him to satisfy his claim. If there are not
    a valid queue does not exist. If there are this is a valid
    queue.
    Finally the program assign heights ranging from 1 to n.
    Starting from the first person at each person it is assigned
    the height that has exactly i heights after it that are not
    already assigned, where i is the number of people taller than
    the current person in front of him in the waiting line.
    The last part consist of scanning the entire array to assign
    just one height in the worst case so the program takes
    O( n^2 ) time.
    Reference: none
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Person{
    string name;
    int a;
};

int main( ) 
{
    int n;
    cin >> n;
    cin.ignore( 1, '\n' );
    vector<Person> input( n );
    for( int i = 0; i < n; i++ ) {
        getline( cin, input[i].name, ' ' );
        cin >> input[i].a;
        cin.ignore( 1, '\n' );
    }
    sort( input.begin( ), input.end( ),
        []( Person& a, Person& b ) {
            return a.a > b.a;
        }
    );
    vector<int> heights( n );
    for( int i = 0; i < n; i++ ) {
        heights[i] = i + 1;
    }
    for( int i = 0; i < n; i++ ) {
        if( n - ( i + 1 ) >= input[i].a ) {
            int j = n - 1;
            int m = input[i].a;
            while( m >= 0 ) {
                if( heights[j] != -1 ) {
                    m--;
                }
                j--;
            }
            input[i].a = heights[j + 1];
            heights[j + 1] = -1;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    for( int i = n - 1; i >= 0; i-- ) {
        cout << input[i].name << " " << input[i].a << endl;
    }
}
