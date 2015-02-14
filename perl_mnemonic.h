#ifndef PERL_FRIENDLY_API
#define PERL_FRIENDLY_API

// TODO:
// we should make a longnames and shortnames with directive
// marked bad aliases with @bad in comments

// data types
#define perl_scalar  SV
#define perl_array   AV
#define perl_hash    HV

/********************************** SCALARS ***********************************/
// fetching variables
#define get_scalar_by_name  get_sv  // SV*  get_sv("package::varname", 0);

// Creating scalars
#define create_scalar                       newSV       // SV*  newSV(int);
#define create_scalar_from_int              newSViv     // SV*  newSViv(IV);
#define create_scalar_from_uint             nevSVuv     // SV*  newSVuv(UV);
#define create_scalar_from_double           newSVnv     // SV*  newSVnv(double);
#define create_scalar_from_string           newSVpv     // SV*  newSVpv(const char*, STRLEN);
#define create_scalar_from_string_sized     newSVpvn    // SV*  newSVpvn(const char*, STRLEN); @bad
#define create_scalar_from_string_formatted newSVpvf    // SV*  newSVpvf(const char*, ...);    @bad
#define create_scalar_from_scalar           newSVsv     // SV*  newSVsv(SV*);

// modifying scalars
#define set_scalar_int                      sv_setiv    // void  sv_setiv(SV*, IV);
#define set_scalar_uint                     sv_setuv    // void  sv_setuv(SV*, UV);
#define set_scalar_double                   sv_setnv    // void  sv_setnv(SV*, double);
#define set_scalar_string                   sv_setpv    // void  sv_setpv(SV*, const char*);
#define set_scalar_string_sized             sv_setpvn   // void  sv_setpvn(SV*, const char*, STRLEN)
#define set_scalar_string_formatted         sv_setpvf   // void  sv_setpvf(SV*, const char*, ...);
#define set_scalar_string_formatted_sized   sv_vsetpvfn // void  sv_vsetpvfn(SV*, const char*, STRLEN, va_list *, SV **, I32, bool *); @bad
#define set_scalar_string_formatted_perl    sv_vsetpvfn // void  sv_vsetpvfn(SV*, const char*, STRLEN, va_list *, SV **, I32, bool *); @bad
#define set_scalar_scalar                   sv_setsv    // void  sv_setsv(SV*, SV*);

// getting scalar values
#define get_scalar_int                  SvIV        // SvIV(SV*)
#define get_scalar_uint                 SvUV        // SvUV(SV*)
#define get_scalar_double               SvNV        // SvNV(SV*)
#define get_scalar_string               SvPV_nolen  // SvPV_nolen(SV*)
#define get_scalar_string_with_length   SvPV        // SvPV(SV*, STRLEN len)
#define is_scalar_true                  SvTRUE      // SvTRUE(SV*)

// check scalar types
#define is_scalar_int               SvIOK   // SvIOK(SV*)
#define is_scalar_double            SvNOK   // SvNOK(SV*)
#define is_scalar_string            SvPOK   // SvPOK(SV*)
#define is_scalar_int_private       SvIOKp  // SvIOK(SV*) @bad
#define is_scalar_double_private    SvNOKp  // SvNOK(SV*) @bad
#define is_scalar_string_private    SvPOKp  // SvPOK(SV*) @bad
#define is_scalar_defined           SvOK    //  SvOK(SV*)

// scalar string ops
#define extend_scalar_string        SvGROW      // SvGROW(SV*, STRLEN newlen)
#define get_scalar_string_length    SvCUR       // SvCUR(SV*)
#define set_scalar_string_length    SvCUR_set   // SvCUR_set(SV*, I32 val)
#define get_scalar_string_end       SvEND       // SvEND(SV*)

#define append_scalar_string                    sv_catpv    // void  sv_catpv(SV*, const char*);
#define append_scalar_string_sized              sv_catpvn   // void  sv_catpvn(SV*, const char*, STRLEN);
#define append_scalar_string_formatted          sv_catpvf   // void  sv_catpvf(SV*, const char*, ...);
#define append_scalar_string_formatted_sized    sv_vcatpvfn // void  sv_vcatpvfn(SV*, const char*, STRLEN, va_list *, SV **, I32, bool); @bad
#define append_scalar_string_formatted_perl     sv_vcatpvfn // void  sv_vcatpvfn(SV*, const char*, STRLEN, va_list *, SV **, I32, bool); @bad
#define append_scalar_scalar                    sv_catsv    // void  sv_catsv(SV*, SV*);

/*********************************** ARRAYS ***********************************/
#define get_array_by_name  get_av  // AV*  get_av("package::varname", 0);

#define create_array                newAV   // AV*  newAV();
#define create_array_from_scalars   av_make // AV*  av_make(SSize_t num, SV **ptr);

#define push_scalar     av_push     // void  av_push(AV*, SV*);
#define pop_scalar      av_pop      // SV*   av_pop(AV*);
#define shift_scalar    av_shift    // SV*   av_shift(AV*);
#define unshift_array   av_unshift  // void  av_unshift(AV*, SSize_t num);

#define get_last_array_index    av_top_index    // SSize_t av_top_index(AV*);
#define get_array_element       av_fetch        // SV**    av_fetch(AV*, SSize_t key, I32 lval);
#define set_array_element       av_store        // SV**    av_store(AV*, SSize_t key, SV* val);

#define clear_array     av_clear    // void  av_clear(AV*);
#define undefine_array  va_undef    // void  av_undef(AV*);
#define extend_array    av_extend   // void  av_extend(AV*, SSize_t key);

/*********************************** HASHES ***********************************/
    
#endif
