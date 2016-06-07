int myAtoi(char* str) {
    int result = 0;
    int sig = 0;
    int temp;
    if(str == NULL){
        return 0;
    }
    for(;*str == ' ';++str);
    if(*str == '+'){
        str++;
    }
    else if(*str == '-'){
        sig = 1;
        str++;
    }
    for(;*str != '\0';str++){
        if(*str >='0' && *str <= '9'){
            temp = result * 10 + *str - '0';
            if(temp/10 != result){
                return sig==0?2147483647:-2147483648;
            }
            else{
                result = temp;
            }
        }
        else{
            break;
        }
    }
    return sig==0?result:-result;
}
