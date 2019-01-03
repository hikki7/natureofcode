//
//  student.hpp
//  functionPsn
//
//  Created by 引田祐樹 on 2018/12/20.
//

#paragma
#ifndef student_hpp
#define student_hpp

#include <stdio.h>
#include "ofMain.h"

class student {
    
public:
    void setid(int _num);
    void setnum(int _num);
    int getid();
    int *getnum() const{
        return (int *)studentnum;
    }
    
private:
    int id;
    int studentnum;
};
#endif /* student_hpp */
