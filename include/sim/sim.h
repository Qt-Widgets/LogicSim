#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include "meta_element.h"
#include "element.h"
#include "basic_elements.h"
#include "file_ops.h"
#include "k_tree.h"

class sim{
    using k_tree_ = tree_ns::k_tree<std::unique_ptr<element>>;
    using k_tree_it = k_tree_::depth_first_node_first_iterator;

    k_tree_ elems;
public:
    sim(){
        elems.set_root(std::make_unique<element>("root"));
    }

    auto root(){
        return elems.root();
    }

    auto set_root(k_tree_::value_type&& val){
        return elems.set_root(std::move(val));
    }

    void tick(){
        for(auto &el:elems){
            el->reset_processed();
            el->process();
        }
    }

    k_tree_it get_by_id(const size_t &id){
        return get_by_id(elems.begin(), elems.end(), id);
    }

    k_tree_it get_by_id(const k_tree_it& begin, const k_tree_it& end, const size_t &id){
        return get_by_predicate(begin, end,
            [&id](auto &el){
            return el->get_id() == id;
        });
    }

    k_tree_it get_by_predicate(std::function<bool(const k_tree_::value_type&)> predicate){
        return std::find_if(elems.begin(), elems.end(), predicate);
    }

    k_tree_it get_by_predicate(const k_tree_it& begin, const k_tree_it& end,
        std::function<bool(const k_tree_::value_type&)> predicate)
    {
        return std::find_if(begin, end, predicate);
    }

    template<class It>
    It erase(It it){
        return elems.erase(it);
    }

    k_tree_it emplace(const k_tree_it& it, k_tree_::value_type&& val){
        return elems.child_append(it, std::move(val));
    }
};