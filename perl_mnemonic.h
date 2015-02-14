/* q

    Idea of this header file came up to me when i've started to dig perlguts the 
    first time. 
    
    Documented API is really invonvenient for a newcomers, hard to remember, 
    easy to make a mistake and hard to find one. In my personal opinion it's 
    very bad when so many methods differs from each other by one letter.
    
    Don't really know what is behind such names, probably some ancient 
    development tools without autocomplete, or just a bad style.

    So, here is my attempt to make it easier for myself and, probably, for other 
    perl diggers.
    
    Of cource, the main purpose is to make writing extensions easier.
    
    You are free to use this file on the same terms as Perl itself. 
    
    Copyright 2015, Alexandr Evstigneev (hurricup@evstigneev.com)

*/
#ifndef PERL_FRIENDLY_API
#define PERL_FRIENDLY_API

// we should make a longnames and shortnames with directive

// data types
#define perl_scalar  SV
#define perl_array   AV
#define perl_hash    HV

// Creating scalars
#define create_scalar                       newSV       // SV*  newSV(int);
#define create_scalar_from_int              newSViv     // SV*  newSViv(IV);
#define create_scalar_from_uint             nevSVuv     // SV*  newSVuv(UV);
#define create_scalar_from_double           newSVnv     // SV*  newSVnv(double);
#define create_scalar_from_string           newSVpv     // SV*  newSVpv(const char*, STRLEN);
#define create_scalar_from_string_sized     newSVpvn    // SV*  newSVpvn(const char*, STRLEN);
#define create_scalar_from_string_formatted newSVpvf    // SV*  newSVpvf(const char*, ...);
#define create_scalar_from_scalar           newSVsv     // SV*  newSVsv(SV*);

// modifying scalars
#define set_scalar_int                      sv_setiv    // void  sv_setiv(SV*, IV);
#define set_scalar_uint                     sv_setuv    // void  sv_setuv(SV*, UV);
#define set_scalar_double                   sv_setnv    // void  sv_setnv(SV*, double);
#define set_scalar_string                   sv_setpv    // void  sv_setpv(SV*, const char*);
#define set_scalar_string_sized             sv_setpvn   // void  sv_setpvn(SV*, const char*, STRLEN)
#define set_scalar_string_formatted         sv_setpvf   // void  sv_setpvf(SV*, const char*, ...);
#define set_scalar_string_formatted_sized   sv_vsetpvfn // void  sv_vsetpvfn(SV*, const char*, STRLEN, va_list *, SV **, I32, bool *);
#define set_scalar_string_formatted_perl    sv_vsetpvfn // void  sv_vsetpvfn(SV*, const char*, STRLEN, va_list *, SV **, I32, bool *);
#define set_scalar_scalar                   sv_setsv    // void  sv_setsv(SV*, SV*);

#endif
