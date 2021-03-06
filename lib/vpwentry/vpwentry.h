#ifndef VMAILMGR__VPWENTRY__H__
#define VMAILMGR__VPWENTRY__H__

#include "mystring/mystring.h"
#include "misc/strlist.h"

struct vpwentry 
{
protected:
  const char* decode_flags(const char*, const char*);
  const char* decode_base(const char*, const char*);
  const char* decode_values(const char*, const char*);

  bool from_ver1_record(const mystring& text);
  bool from_ver2_record(const mystring& text);
  bool from_old_record(const mystring& text);
  
  void set_defaults(bool ctime_now, bool set_flags);

public:
  mystring name;
  mystring pass;
  mystring directory;
  mystring forwards;
  mystring personal;
  unsigned hardquota;
  unsigned softquota;
  unsigned msgsize;
  unsigned msgcount;
  unsigned ctime;
  unsigned expiry;
  bool has_mailbox;
  bool is_mailbox_enabled;
  // keystrlist data;
  
private:
  vpwentry();

public:
  static vpwentry* new_from_record(const mystring& name, const mystring& text);
  
  vpwentry(const mystring&, const mystring&, const mystring&, const mystring&,
	   bool);
  ~vpwentry();

  //mystring get(const mystring& var) const { return data.get(var); }
  //void set(const mystring& var, const mystring& val)
  //  {
  //    return data.set(var, val);
  //  }

  bool authenticate(const mystring& phrase) const;

  bool from_record(const mystring& name, const mystring& text);
  mystring to_record() const;

  bool export_env() const;
};

#endif
