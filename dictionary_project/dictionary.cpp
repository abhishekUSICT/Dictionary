#include<bits/stdc++.h>
using namespace std;
struct node
{
    char ch;
    bool end;
    string meaning;
    node* n[26];
    node(char c)
    {
        for(int i=0;i<26;i++)
            n[i]=NULL;
        ch=c;
        meaning="";
        end=false;
    }
};
void insert(string s,node* root,string p)
{
    if(!s.size())
    {
        root->end=true;
        root->meaning=p;
        return;
    }
    if(root->n[s[0]-'a']==NULL)
        root->n[s[0]-'a']=new node(s[0]);
    insert(s.substr(1),root->n[s[0]-'a'],p);
}
string search(string s,node* root)
{
    if(!s.size())
    {
        if(root->end==true)
            return root->meaning;
        return "No such word exist";
    }
    if(root->n[s[0]-'a']==NULL)
        return "No such word exist";
    return search(s.substr(1),root->n[s[0]-'a']);
}
int main()
{
    int n,i;
    char choice;
    node *root=new node(0);
    cout<<"Enter number of words you want to store in dictionary:-"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter word number "<<i+1<<":- ";
        string s,p;
        cin>>s;
        cout<<"Enter the meaning of word:- ";
        cin.ignore();
        getline(cin,p);
        insert(s,root,p);
    }
    do
    {
        cout<<"Enter the word to be searched:- "<<endl;
        string s;
        cin>>s;
        string answer=search(s,root);
        if(answer=="No such word exist")
            cout<<answer<<endl;
        else
            cout<<"meaning of "<<s<<" is:- "<<answer<<endl;
        cout<<"Do you want to continue ? (y/n)"<<endl;
        cin>>choice;
    }while(choice=='y');
    return 0;
}