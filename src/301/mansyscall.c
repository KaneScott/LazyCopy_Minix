#include lib.h;
/* 70 */
PUBLIC main(int argc, char *argv[]){
  Message m = new Message();
  m->m_type = 70;
  _sendrec(m);
}
