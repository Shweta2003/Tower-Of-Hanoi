// Include header file
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <iomanip>
using namespace std;
/*
  C++ program for
  Tower of hanoi solution
*/

class lf{
  public:
    int left;
    int right;
};


// to keep track of filled pole
int h = 0;
lf pole[3];
int ytop = 30;
int ybar[3];
int MAX;



class Test
{
public:
  void pop_disk(int pole_no, int d, int i);
  void set_disk(int pole_no, int disk, int i);
  //void pop_disk(int pole_no, int disk, int i);
  void shift_right(int pole_no_initial, int pole_no_final, int disk, int i);
  void shift_left(int pole_no_initial, int pole_no_final, int disk, int i);

  // Recursive solution
  void towerOfHanoi(int * disk_arr, int disk, int source,
                    int destination,
                    int auxiliary)
  {
    if (disk <= 0)
    {
      // Base condition to control recursion
      return;
    }
    // Reduce disk by one and execute tower Of Hanoi method
    this->towerOfHanoi(disk_arr,(disk - 1), source,
                       auxiliary, destination);
    // Display movement of disk
    cout << " \t\t\t   Move disk " << disk << " from tower ["
         << source << "] to  ["
         << destination << "]" << endl;
    pop_disk(source - 1,disk_arr[MAX - disk],MAX - disk);
    if(source < destination){
      shift_right(source - 1, destination - 1, disk_arr[MAX - disk], MAX - disk);
    }
    else{
      shift_left(source - 1, destination - 1, disk_arr[MAX - disk], MAX - disk);
    }
    set_disk(destination - 1, disk_arr[MAX - disk], MAX - disk);

    // Reduce disk by one
    // And change the position
    this->towerOfHanoi(disk_arr,disk - 1, auxiliary,
                       destination, source);
  }
};

void Test ::set_disk(int pole_no, int disk, int i)
{
  for (int y = ytop - 1; y <= ybar[pole_no] - h - 1; y ++)
  {
    setcolor(i + 1);
    int diff = pole[pole_no].left + (((pole[pole_no].right - pole[pole_no].left) - disk) / 2);
    rectangle(diff, y, diff + disk, y + h);
    setfillstyle(SOLID_FILL, i+1);
    floodfill(diff + 10, y + 5, i+1);
    delay(10);

    if (y < ybar[pole_no] - h - 1)
    {
      setcolor(0);
      rectangle(diff, y, diff + disk, y + h);
      setfillstyle(SOLID_FILL, BLACK);
      floodfill(diff + 10, y + 5, 0);
    }
  }
  ybar[pole_no] = ybar[pole_no] - h - 1;
}

void Test :: pop_disk(int pole_no, int d, int i){
  
  for (int y1 = ybar[pole_no]; y1 >= ytop - 1 ; y1 --)
  {
    int diff = pole[pole_no].left + (((pole[pole_no].right - pole[pole_no].left) - d) / 2);

    setcolor(i + 1);
    rectangle(diff, y1, diff + d, y1 + h);
    setfillstyle(SOLID_FILL, i+1);
    floodfill(diff + 10, y1 + 5 + 5, i+1);
    delay(10);
    if (y1 >= ytop)
    {
      setcolor(0);
      delay(0);
      rectangle(diff, y1, diff + d, y1 + h);
      setfillstyle(SOLID_FILL, BLACK);
      floodfill(diff + 10, y1 + 5, 0);
    } 
  }
  ybar[pole_no] = ybar[pole_no] + h + 1;
}

void Test :: shift_right(int pole_no_initial, int pole_no_final, int disk, int i){
  ytop --;
  int diff = ((pole[pole_no_initial].right - pole[pole_no_initial].left) - disk) / 2;
  for (int q = pole[pole_no_initial].left ; q <= pole[pole_no_final].left ; q ++){
    
    setcolor(i + 1);
    rectangle(q + diff, ytop, q + diff + disk, ytop + h);
    setfillstyle(SOLID_FILL, i+1);
    floodfill(q + diff + 10, ytop + 5 , i+1);
    delay(10);

    if (q < pole[pole_no_final].left)
    {
      setcolor(BLACK);
      delay(0);
      rectangle(q + diff - 1, ytop, q + diff + disk - 1, ytop + h);
      setfillstyle(SOLID_FILL, BLACK);
      floodfill(q + diff + 10, ytop + 5, 0);
    }
     
  }
  ytop ++;
}

void Test :: shift_left(int pole_no_initial, int pole_no_final, int disk, int i){
  ytop --;
  int diff = ((pole[pole_no_initial].right - pole[pole_no_initial].left) - disk) / 2;
  for (int q = pole[pole_no_initial].left ; q >= pole[pole_no_final].left ; q --){
    
    setcolor(i + 1);
    rectangle(q + diff, ytop, q + diff + disk, ytop + h);
    setfillstyle(SOLID_FILL, i+1);
    floodfill(q + diff + 10, ytop + 5 , i+1);
    delay(10);

    if (q > pole[pole_no_final].left)
    {
      setcolor(BLACK);
      delay(0);
      rectangle(q + diff + 1, ytop, q + diff + disk + 1, ytop + h);
      setfillstyle(SOLID_FILL, BLACK);
      floodfill(q + diff + 10, ytop + 5, 0);
    }
     
  }
  ytop ++;
}

int main()
{
  Test *task = new Test();

  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TC\\BGI");
  // name of project
  setcolor(15);
  char *name = "TOWER OF HANOI";
  settextstyle(9, 4, 4);
  outtextxy(getmaxx() - 140, getmaxy() - 80, name);

  // pole coordinates
  pole[0].left = getmaxx() / 10;
  pole[0].right = getmaxx() * 3 / 10;
  pole[1].left = getmaxx() * 4 / 10;
  pole[1].right = getmaxx() * 6 / 10;
  pole[2].left = getmaxx() * 7 / 10;
  pole[2].right = getmaxx() * 9 / 10;
  int k = 0;
  int poley1 = getmaxy() / 4;
  int poley2 = getmaxy() * 2 / 3;

  // main background
  for (int i = 0; i < 3; i ++)
  {
    if (i == 2)
    {
      k = 14;
      setcolor(k);
    }
    else
    {
      k = 15;
      setcolor(k);
    }
    rectangle(pole[i].left - 10, poley1, pole[i].left, poley2);
    setfillstyle(SOLID_FILL, k);
    floodfill(pole[i].left - 5, poley1 + 5, k);
    rectangle(pole[i].left - 10, poley2, pole[i].right + 10, poley2 + 10);
    floodfill(pole[i].left + 5, poley2 + 5, k);
    rectangle(pole[i].right, poley1, pole[i].right + 10, poley2);
    floodfill(pole[i].right + 5, poley1 + 5, k);
  }
  cout << setw(10) << "\n";
  cout << setfill('*') << setw(100) << "\n";
  cout << setfill('*') << setw(100) << "\n";
  cout <<"\n\t\t\t\tWELCOME TO BY PROJECT\n\n";
  cout << setfill('*') << setw(100) << "\n";
  cout << setfill('*') << setw(100) << "\n";
  cout <<"\n\t\t\t\t    TOWER OF HANOI\n\n";
  cout << setfill('*') << setw(100) << "\n";
  cout << setfill('*') << setw(100) << "\n";
  cout << "\nRules : \n";
  cout << "\n1. We need to move all the disks from handle one to handle 3 (YELLOW) is the destination\n";
  cout << "2. We can only move one disk at a time.\n";
  cout << "3. No bigger disk can sit on the smaller disk. \n";
  cout << "\n\t\t\t   How will you solve the problem?\n\t\t\t\t    LET'S FIND OUT!!!\n\n";
  cout << setfill('*') << setw(100) << "\n";

  cout << "\nEnter number of disks present : ";
  cin >> MAX;
  cout << "\n";
  cout << setfill('*') << setw(100) << "\n";
  h = (poley2 - poley1) / MAX;
  ybar[0] = poley2;
  ybar[1] = poley2;
  ybar[2] = poley2;
  // create initial disks in pole 1
  int disk_arr[MAX];
  for (int i = 0; i < MAX; i++)
  {
    disk_arr[i] = ((pole[0].right - pole[0].left) * (MAX - i) / MAX);
    task->set_disk(0, disk_arr[i], i);
  }
  // Test
  // Here 1,3, 2 is indicate rods
  task->towerOfHanoi(disk_arr,MAX, 1, 3, 2);
  getch();
  closegraph();
  return 0;
}