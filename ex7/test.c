int main(int argc, char const *argv[])
{
    char exp1[0x10], exp2[0x10];
    char src_buf[0x10];
    copy_from_user(exp1, src_buf, 0x10);
    {
        int i = 1;
        i++;
    }
    copy_from_user(exp2, src_buf, 0x10);
    return 0;
}
