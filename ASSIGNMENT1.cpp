#include<iostream>
#include<cstring>
using namespace std;
class employee{
    public:
    string sname;
    int  iempid;
};
class hashtable{
    private:
    employee record[10];
    public:
    hashtable(){
        for (int i=0;i<3;i++){
            record[i].sname="";
            record[i].iempid=-1;
        }
    }
    int hashvalue(int number){
        return(number% 3);
    }
     void insertrecord(string name,int id)
     {
        int index = hashvalue(id);
        if(record[index].iempid==-1){
            record[index].iempid = id;
            record[index].sname =name;
        }
        else{
            int inew_index = index+1;
            while(inew_index!=index){
                if(record[inew_index].iempid==-1){
                    record[inew_index].iempid=id;
                    record[inew_index].sname=name;
                    break;
                }
            }
            inew_index=(inew_index+1)%10;
        }
     }
     void display()
     {
        for(int i=0;i<3;i++){
            if(record[i].iempid!=-1){
                cout<<"name:"<<record[i].sname<<endl<<"id:"<<record[i].iempid<<endl;
            }
        }
    
     }
};
int main()
{
   hashtable ht;
   for(int i=0;i<3;i++)
   {
      string name;
      int id;
      cout<<"enter details of empolyee"<<i+1<<":"<<endl;
      cout<<"name:";
      cin>>name;
      cout<<"id:";
      cin>>id;
      ht.insertrecord(name,id);

   }
   ht.display();
}

