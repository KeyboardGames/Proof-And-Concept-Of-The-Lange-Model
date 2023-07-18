#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cstdlib> 
#include <ctime> 
#include <fstream>
#include <sstream>
#include <time.h>

int main(){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    //get file input of data
    std::string pathFI;
    std::cout<<"FILE MUST BE 4 LINES OR LONGER"<<std::endl;
    std::cout<<"PARAMETERS:"<<std::endl;
    std::cout<<"[Yesterday's Number]"<<std::endl;
    std::cout<<"[Supply],[Marginal Cost],[Price]"<<std::endl;
    std::cout<<"[Today's Number]"<<std::endl;
    std::cout<<"[Supply],[Marginal Cost],[Price]"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"Enter Input File's Path: ";
    std::getline(std::cin, pathFI);
    //count lines of file to see if this is it's first time being ran
    int countFileI=0;
    std::string countFileS;
    std::ifstream countFileF;
    countFileF.open(pathFI.c_str());
    while(std::getline(countFileF, countFileS)){
        countFileI=countFileI+1;
    }
    countFileF.close();
    if(countFileI<=3){
        std::cout<<"Invalid File!"<<std::endl;
    }
    if(countFileI>=4){
        //get data from past day
        int countDataS=1;
        std::string dateS;
        std::string curdata1S;
        std::string curdata2S;
        std::string getDataS;
        std::ifstream getDataF;
        getDataF.open(pathFI.c_str());
        while(std::getline(getDataF, getDataS)){
            if(countDataS==countFileI-1){
                std::ostringstream dateSO;
                dateSO<<""<<getDataS<<"";
                dateS=dateSO.str();
            }
            if(countDataS==countFileI-2){
                std::ostringstream curdata1SO;
                curdata1SO<<""<<getDataS<<"";
                curdata1S=curdata1SO.str();
            }
            if(countDataS==countFileI){
                std::ostringstream curdata2SO;
                curdata2SO<<""<<getDataS<<"";
                curdata2S=curdata2SO.str();
            }
            countDataS=countDataS+1;
        }
        getDataF.close();
        
        std::ostringstream dateSIO;
        dateSIO<<""<<dateS<<"";
        std::string dateSI = dateSIO.str();
        int dateSII;
        std::istringstream (dateSI)>>dateSII;

        //extract supply, mc, and p
        double supply1I;
        std::ostringstream supply1IO;
        double marginalI=0;
        std::ostringstream marginalIO;
        double priceI=0;
        std::ostringstream priceIO;
        int lengthD1=curdata1S.length();
        int nextC1=1;
        for(int SF1=0; SF1<=lengthD1; SF1++){
            int changeAC=2;
            if(curdata1S[SF1]==(',')){
                changeAC=1;
            }
            if(nextC1==1 && changeAC==2){
                supply1IO<<""<<curdata1S[SF1]<<"";
            }
            if(nextC1==2 && changeAC==2){
                marginalIO<<""<<curdata1S[SF1]<<"";
            }
            if(nextC1==3 && changeAC==2){
                priceIO<<""<<curdata1S[SF1]<<"";
            }
            if(curdata1S[SF1]==(',') && changeAC==1){
                nextC1=nextC1+1;
            }
        }
        std::string supply1IOS=supply1IO.str();
        std::string marginalIOS=marginalIO.str();
        std::string priceIOS=priceIO.str();
        std::istringstream (supply1IOS)>>supply1I;
        std::istringstream (marginalIOS)>>marginalI;
        std::istringstream (priceIOS)>>priceI;

        double supply2I=0;
        std::ostringstream supply2IO;
        int lengthD2=curdata2S.length();
        int changeACP=1;
        for(int SF2=0; SF2<=lengthD2; SF2++){
            int changeAC2=2;
            if(curdata2S[SF2]==(',')){
                changeAC2=1;
            }
            if(changeACP==1 && changeAC2==2){
                supply2IO<<""<<curdata2S[SF2]<<"";
            }
            if(changeAC2==1){
                changeACP=changeACP+1;
            }
        }
        std::string supply2IOS=supply2IO.str();
        std::istringstream(supply2IOS)>>supply2I;
        //print overall results
        std::cout<<"Yesterday: "<<dateSII-1<<""<<std::endl;
        std::cout<<"Supply: "<<supply1I<<", Marginal Cost: "<<marginalI<<", Price: "<<priceI<<", Profit: "<<priceI-marginalI<<""<<std::endl;
        std::cout<<"Today: "<<dateSII<<""<<std::endl;
        std::cout<<"Supply: "<<supply2I<<", Marginal Cost: "<<marginalI<<", Price: "<<priceI<<", Profit: "<<priceI-marginalI<<""<<std::endl;
        double priceSug=0;
        int priceII=priceI;
        std::ostringstream priceISO;
        priceISO<<""<<priceII<<"";
        std::string priceIS=priceISO.str();
        int priceIL=priceIS.length();
        int limitI=std::pow(10,priceIL-1);
        int divideLI=priceI/limitI;
        int limitII=divideLI*limitI;
        int workA=2;
    if(supply1I==supply2I){
        std::cout<<"AT EQUILIBRIUM (or close enough)"<<std::endl;
        workA=1;
    }
    if(workA==2){
    if(supply2I<supply1I-supply1I/2){
        priceSug=priceI+1.0*limitII;
    }
    if(supply2I>supply1I+supply1I/2){
        priceSug=priceI-1.0*limitII;
    }	
    if(supply2I<supply1I-supply1I/4 && supply2I>supply1I-supply1I/2){
        priceSug=priceI+0.5*limitII;
    }
    if(supply2I>supply1I+supply1I/4 && supply2I<supply1I+supply1I/2){
        priceSug=priceI-0.5*limitII;
    }	
    if(supply2I<supply1I-supply1I/8 && supply2I>=supply1I-supply1I/4){
        priceSug=priceI+0.25*limitII;
    }
    if(supply2I>supply1I+supply1I/8 && supply2I<=supply1I+supply1I/4){
        priceSug=priceI-0.25*limitII;
    }	
    if(supply2I<supply1I && supply2I>=supply1I-supply1I/8){
        priceSug=priceI+0.1125*limitII;
    }
    if(supply2I>=supply1I && supply2I<=supply1I+supply1I/8){
        priceSug=priceI-0.1125*limitII;
    }	
    }
    double profitS=priceSug-marginalI;
    std::cout<<""<<std::endl;
    std::cout<<"Suggested:"<<std::endl;
    std::cout<<"Price: "<<priceSug<<", Profit: "<<profitS<<""<<std::endl;
    }
    exit(0);
    return 0;
}
