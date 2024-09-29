#include <istream>
#include <string>

#include "HeapArrays.h"
#include "StackArrays.h"
#include "defs.h"


bool testStackObjectArray();
bool testStackPointerArray();
bool testHeapObjectArray();
bool testHeapPointerArray();

extern const string content[12];

int main(){

    int choice = 0;
    cout<<"Enter one of the following options: "<<endl;
    cout<<"0. Test StackArrays::getObjectArray"<<endl;
    cout<<"1. Test StackArrays::getPointerArray"<<endl;
    cout<<"2. Test HeapArrays::getObjectArray"<<endl;
    cout<<"3. Test HeapArrays::getPointerArray"<<endl;
    cin >> choice;
    bool flag = true;
    switch(choice){
      case 0: flag = testStackObjectArray(); break;
      case 1: flag = testStackPointerArray(); break;
      case 2: flag = testHeapObjectArray(); break;
      case 3: flag = testHeapPointerArray(); break;
    }
    
    
    if (flag){
      return 0;
    }else{
      return 1;
    }
  
}

bool testHeapObjectArray(){
  HeapArrays ha;
  string title;
  cout<<"Enter 3 titles (separated by spaces): "<<endl;
  for (int i = 0; i < 3; ++i){
      cin >> title;
      Video video(title, content[i]);
      ha.addVideo(video);
  }
  Video* video = ha.getObjectArray();
  for (int i = 0; i < MAX_ARRAY; ++i){
    // ha.getVideoReference(i).play();
    video[i].play();
    if (&video[i]!=&ha.getVideoReference(i)){
      cout<<"Wrong object returned by getVideoReference"<<endl;
      return false;
    }
  }
  cout<<"testHeapObjectArray passed"<<endl;
  return true;
}

bool testHeapPointerArray(){
  HeapArrays ha;
  string title;
  cout<<"Enter 3 titles (separated by spaces): "<<endl;

  for (int i = 0; i < 3; ++i){
      cin >> title;
      Video video(title, content[i]);
      ha.addVideo(video);
  }
  Video** video = ha.getPointerArray();
  for (int i = 0; i < MAX_ARRAY; ++i){
    //ha.getVideoPointer(i)->play();
    (*video[i]).play();
    if (video[i]!=ha.getVideoPointer(i)){
      cout<<"Wrong object returned by getVideoPointer"<<endl;
      return false;
    }
  }
  cout<<"testHeapPointerArray passed"<<endl;
  return true;
}

bool testStackObjectArray(){
  StackArrays sa;
  string title;
  cout<<"Enter 3 titles (separated by spaces): "<<endl;
  for (int i = 0; i < MAX_ARRAY; ++i){
      cin >> title;
      Video video(title, content[i]);
      sa.addVideo(video);
  }
  Video* video = sa.getObjectArray();
  for (int i = 0; i < MAX_ARRAY; ++i){
    //sa.getVideoReference(i).play();
    video[i].play();
    if (&video[i]!=&sa.getVideoReference(i)){
      cout<<"Wrong object returned by getVideoReference"<<endl;
      return false;
    }
  }
  cout<<"testStackObjectArray passed"<<endl;
  return true;
}

bool testStackPointerArray(){
  StackArrays sa;
  string title;
  cout<<"Enter 3 titles (separated by spaces): "<<endl;
  for (int i = 0; i < MAX_ARRAY; ++i){
      cin >> title;
      Video video(title, content[i]);
      sa.addVideo(video);
  }
  Video** video = sa.getPointerArray();
  for (int i = 0; i < MAX_ARRAY; ++i){
    //sa.getVideoPointer(i)->play();
    (*video[i]).play();
    if (video[i]!=sa.getVideoPointer(i)){
      cout<<"Wrong object returned by getVideoPointer"<<endl;
      return false;
    }
  }
  cout<<"testStackPointerArray passed"<<endl;
  return true;
}

const string content[12] = {
R"(picture
  ___
 / _ \
| (_) |
 \___/
)",

R"(picture
  ,--.
 /  0 \
|   .  |
 \___/
)",

R"(picture
  ,--.
 /  0 \
|   |  |
 \___/
)",

R"(
  ,--.
 /  0 \
|   |  |
 \__O/
)",

R"(
   /\
  /  \
 |    |
 |----|
 |    |
 |----|
)",

R"(
   /\
  /  \
 | [] |
 |----|
 |    |
 |----|
)",

R"(
 ______
/ 0  0 \
|    ∆   |
 \_____/
)",

R"(
  ____
 /  00\
|    0 |
|______|
)",

R"(
   ,--.
  / 00\
 |  |  |
  \__/
)",

R"(
  ,--,
 /    \
|  ☏   |
 \    /
  '--'
)",

R"(
   ,--.
  / 00\
 |  |  |
  \__/
)",

R"(
  ,--,
 /    \
|  ☏   |
 \    /
  '--'
)"
};