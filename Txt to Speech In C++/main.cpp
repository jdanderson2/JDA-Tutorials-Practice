#include <bits/stdc++.h>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <ctime>

using namespace std;

// function to greet the user according to time
void greetings(){
    // current date  and time based on your system timezone
    time_t now = time(0);
    tm *time = localtime(&now);


