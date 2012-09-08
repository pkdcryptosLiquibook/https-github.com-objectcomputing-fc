#ifndef _FC_UNIQUE_LOCK_HPP_
#define _FC_UNIQUE_LOCK_HPP_

namespace fc {
  
  /**
   *  Including Boost's unique lock drastically increases compile times
   *  for something that is this trivial!
   */
  template<typename T>
  class unique_lock  {
    public:
      unique_lock( T& l ):_lock(l) { _lock.lock();   }
      ~unique_lock()               { _lock.unlock(); }
    private:
      unique_lock( const unique_lock& );
      unique_lock& operator=( const unique_lock& );
      T&  _lock;
  };

}

/**
 *  Emulate java with the one quirk that the open bracket must come before
 *  the synchronized 'keyword'. 
 *  
 *  <code>
    { synchronized( lock_type ) 

    }
 *  </code>
 */
#define synchronized(X)  fc::unique_lock<decltype((X))> __lock(((X)));

#endif
