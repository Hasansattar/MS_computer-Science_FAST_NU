from source to destination"<<endl;
            }
            else
                cout<<"Move the disk "<<s.top()<<" from destination to source"<<endl;
            }
            else if(i%3==2){
            int y=transfer_disk(s,a);
            if(y==1){
                cout<<"Move the disk "<<a.top()<<" from source to auxiliary"<<endl;
            }
            else
                cout<<"Move the disk "<<s.top()<<" from auxiliary to source"<<endl;
            }
            else{
            int y=transfer_disk(a,d);
            if(y==1){
                cout<<"Move the disk "<<d.top()<<" from auxiliary to destination"<<endl;
            }
            else
                cout<<"Move the disk "<<a.top()<<" from destination to auxiliary"<<endl;
            }
            i++;
    }
}
    

while(d.empty()!=true){
        cout<<d.top()<<endl;
        d.pop();
    }
    
    
return 0;
}