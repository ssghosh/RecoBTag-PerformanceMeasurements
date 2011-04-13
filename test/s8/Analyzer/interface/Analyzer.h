/**
 * Analyzer
 * s8
 *
 * Created by Samvel Khalatian on Nov 12, 2010
 * Copyright 2010, All rights reserved
 */

#ifndef S8_ANALYZER
#define S8_ANALYZER

#include <iosfwd>

class TDirectory;

namespace s8
{
    class Event;
    class TreeInfo;
    class TriggerCenter;

    class Analyzer
    {
        public:
            Analyzer() throw();
            virtual ~Analyzer() throw();

            virtual void init() = 0;

            virtual void treeDidLoad(const TreeInfo *, const TriggerCenter *);

            virtual void eventDidLoad(const Event *) = 0;

            // Print summary
            //
            virtual void print(std::ostream &) const = 0;

            // Save results
            //
            virtual void save(TDirectory *) const = 0;
    };

    std::ostream &operator<<(std::ostream &, const Analyzer &);
}

#endif
