#include<bits/stdc++.h>
#include"MyVector.cpp"
using namespace std;

class KhachHang{
		string hoten;
		int makh;
		int sdt;
		public:
			KhachHang(){
			};
			KhachHang(string hoten,int makh,int sdt){
				this->hoten=hoten;
				this->makh=makh;
				this->sdt=sdt;
			}
			int getma(){
				return makh;
			}
			void setname(string hoten);
			string getname();
			int searchphone(MyVector<KhachHang> &kh,int phone);
			void searchma(MyVector<KhachHang> &kh,KhachHang a);
			void sapxepma(MyVector<KhachHang> &kh);
			void sapxepten(MyVector<KhachHang> &kh);
			friend istream &operator >> (istream &is,KhachHang &a){
				cout<<"Nhap ma khach hang:";
				is>>a.makh;
				cout<<"Nhap Ho ten:";
				is.ignore();
				getline(is,a.hoten);
				cout<<"Nhap so dien thoai:";
				is>>a.sdt;
			}
			friend ostream &operator << (ostream &os,KhachHang a){
				
				os<<"Ma Khach Hang:"<<a.makh<<endl;
				os<<"Ho ten:"<<a.hoten<<endl;
				os<<"So dien thoai:"<<a.sdt<<endl;
			}
	};
void output(MyVector<KhachHang> &kh){
	for(int i=0;i<kh.size();i++){
		cout<<endl<<"Khach hang thu "<<i+1<<":"<<endl;
		cout<<kh[i];
	}
}
void KhachHang::setname(string hoten){
	this->hoten=hoten;
}
string KhachHang::getname(){
	return this->hoten;
}
int KhachHang::searchphone(MyVector<KhachHang> &kh,int phone){
	int dem=0,k=0;
	
	for(int i=0;i<kh.size();i++){
		if(kh[i].sdt==phone){
			kh.erase(i);
		}else{
			dem++;
		}
		k++;
	}
	if(dem==k){
		return 1;
		
	}else{
		
		return 0;
	}
}
void KhachHang::searchma(MyVector<KhachHang> &kh,KhachHang a){
	int ma,dem=0,k=0;
	char yn[2];
	cout<<endl<<"Nhap ma khach hang can sua:";
	cin>>ma;
	for(int i=0;i<kh.size();i++){
		if(kh[i].makh!=ma){
			dem++;
		}
		k++;
	}
	if(dem==k){
		cout<<endl<<"Khong co khach hang co ma khach hang do"<<endl;
	}else{
		cout<<endl<<"Khach hang can sua thong tin la:"<<endl;
		for(int i=0;i<kh.size();i++){
			if(kh[i].makh==ma){
				cout<<endl<<"Khach hang thu "<<i+1<<":"<<endl;
				cout<<kh[i];
				cout<<"Ban co muon sua khong(Y/N)?";
        		cin>>yn;
        		if(strcmpi(yn,"y")==0){
        			cout<"Thong tin sua:";
        			cin>>a;
        			kh.erase(i);
        			kh.insert(i,a);
				}
			}
		}
	}
}
void KhachHang::sapxepten(MyVector<KhachHang> &kh){
	/*
	KhachHang tmp;
	for (int i = 0; i < kh.size(); ++i) 
	{
		for (int j = i + 1; j < kh.size(); ++j) 
		{
			if (kh[i].hoten>kh[j].hoten)
			{
				tmp = kh[i];
				kh[i] = kh[j];
				kh[j] = tmp;
			}
		}
	}*/
	kh.quickSortten(kh,0,kh.size()-1);

}
void KhachHang::sapxepma(MyVector<KhachHang> &kh){
	/*KhachHang tmp;
	for (int i = 0; i < kh.size(); ++i) 
	{
		for (int j = i + 1; j < kh.size(); ++j) 
		{
			if (kh[i].makh > kh[j].makh)
			{
				tmp = kh[i];
				kh[i] = kh[j];
				kh[j] = tmp;
			}
		}
	}*/
	kh.quickSortma(kh,0,kh.size()-1);
}
int main(){
   	KhachHang a;
	MyVector<KhachHang> kh;
    int i=0;
    char yn[2];
    int choose;
    cout << "================MENU================" << endl;
	cout << "0. Thoat." << endl;
	cout << "1. Them khach hang." << endl;
	cout << "2. Xoa khach hang theo so dien thoai." << endl;
	cout << "3. Sua thong tin khach hang bat ky." << endl;
	cout << "4. Sap xep danh sach khach hang theo ma khach hang." << endl;
	cout << "5. Sap xep danh sach khach hang theo ho ten." << endl;
	cout << "6. Hien thi toan bo dan sach khach hang hien co." << endl;
	cout << "7. Ghi danh sach khach hang vao file." << endl;
	cout << "================END================" << endl;
	do{
		cout<<"Nhap lua chon cua ban:";
		cin>>choose;
		switch (choose){
			case 0:
				cout<<"GOOD BYE!!";
				break;
			case 1:
				//Nhap thong tin va hoi nhap tiep
				do{
			        cin >> a;
			        kh.push_back(a);
			        cout<<"Ban co muon nhap tiep khong(Y/N)?";
			        cin>>yn;
    			}while(strcmpi(yn,"y")==0);
    			output(kh);
    			break;
    		case 2:
	    		//tim sdt can xoa
	    		int phone;
	    		if(kh.size()==0){
					cout<<endl<<"Danh sach trong"<<endl;
				}else{
		    		cout<<endl<<"Nhap so dien thoai can xoa: ";
					cin>>phone;
					if(a.searchphone(kh,phone)==1){
						cout<<endl<<"Khong co khach hang co so dien thoai can xoa"<<endl;
					}else{
						cout<<endl<<"Danh sach sau khi xoa:"<<endl;
						output(kh);
					}
				}
				break;
			case 3:
				//thay doi thong tin
				if(kh.size()==0){
					cout<<endl<<"Danh sach trong"<<endl;
				}else{
					a.searchma(kh,a);
					output(kh);
				}
				break;
			case 4:	
				// sap xep theo ma kh
				if(kh.size()==0){
					cout<<endl<<"Danh sach trong"<<endl;
				}else{
					cout<<endl<<"Danh sach sau khi sap xep theo Ma Khach Hang:"<<endl;
					a.sapxepma(kh);
					output(kh);	
				}
				break;
			case 5:
				// sap xep theo ho ten
				if(kh.size()==0){
					cout<<endl<<"Danh sach trong"<<endl;
				}else{
					cout<<endl<<"Danh sach sau khi sap xep theo Ho ten:"<<endl;
					a.sapxepten(kh);
					output(kh);
				}
				break;
			case 6:
				//in danh sach
				if(kh.size()==0){
					cout<<endl<<"Danh sach trong"<<endl;
				}else{
					cout<<endl<<"Toan bo danh sach hien co:"<<endl;
					output(kh);
				}
				break;
			case 7:
				//ghi len file
				ofstream outfile;
				outfile.open("filetxt.txt");
				if(kh.size()==0){
					outfile<<endl<<"Danh sach trong"<<endl;
				}else{
					for(i=0;i<kh.size();i++)
					outfile<<"Khach hang "<<i+1<<":"<<endl<<a<<endl;
				}
				cout<<endl<<"Danh sach khach hang da duoc ghi len file 'Danhsachkhachhang.txt'."<<endl;
				outfile.close();
				break;
		}
	}while(choose);	
}
