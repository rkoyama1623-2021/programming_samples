// -*- coding : utf-8 -*-
// -*- c-basic-offset : 2 -*-
#include <iostream>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/ordered_index.hpp>

struct person {
    std::string name;
    int id;
    person(std::string const & name, int id) 
    : name(name), id(id) { 
    }
};

int main() {

    using namespace::boost::multi_index;
    using namespace std;

    // define a multi_index_container with a list-like index and an ordered index
    typedef multi_index_container<
      person,        // The type of the elements stored
      indexed_by<    // The indices that our container will support
        sequenced<>,                           // list-like index
        ordered_unique<member<person, string, &person::name> > // map-like index (sorted by name)
      >
    > person_container;

    // Create our container and add some people
    person_container persons;
    persons.push_back(person("B", 123));
    persons.push_back(person("C", 224));
    persons.push_back(person("A", 321));

    // Typedefs for the sequence index and the ordered index
    enum { Seq, Ord };
    typedef person_container::nth_index<Seq>::type persons_seq_index;
    typedef person_container::nth_index<Ord>::type persons_ord_index;

    // Let's test the sequence index
    persons_seq_index & seq_index = persons.get<Seq>();
    for(persons_seq_index::iterator it = seq_index.begin(), 
                                    e = seq_index.end(); it != e; ++it)
        cout << it->name << ":"<< it->id << endl;
    cout << "\n";

    // And now the ordered index
    persons_ord_index & ord_index = persons.get<Ord>();
    for(persons_ord_index::iterator it = ord_index.begin(), 
                                    e = ord_index.end(); it != e; ++it)
        cout << it->name << ":"<< it->id << endl;
    cout << "\n";

    // Thanks to the ordered index we have fast lookup by name:
    std::cout << "The id of B is: " << ord_index.find("B")->id << "\n";
}
