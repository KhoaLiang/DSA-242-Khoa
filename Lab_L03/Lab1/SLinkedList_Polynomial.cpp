void Polynomial::insertTerm(const Term& term) {
    // Skip if coefficient is zero
    if (term.coeff == 0) return;

    // Find the correct position to insert the term (descending order by exponent)
    SLinkedList<Term>::Iterator it;
    bool termInserted = false;
    
    // First, check if we need to update an existing term
    for (it = this->terms->begin(); it != this->terms->end(); it++) {
        // If we find a term with the same exponent, add coefficients
        if ((*it).exp == term.exp) {
            double newCoeff = (*it).coeff + term.coeff;
            
            // If the resulting coefficient is zero, remove the term
            if (newCoeff == 0) {
                // Since we can't use erase directly with iterator, find the index and remove
                int index = 0;
                SLinkedList<Term>::Iterator temp = this->terms->begin();
                while (temp != it) {
                    temp++;
                    index++;
                }
                this->terms->removeAt(index);
            } else {
                // Create updated term and replace by finding the index
                Term updatedTerm(newCoeff, term.exp);
                int index = 0;
                SLinkedList<Term>::Iterator temp = this->terms->begin();
                while (temp != it) {
                    temp++;
                    index++;
                }
                this->terms->set(index, updatedTerm);
            }
            termInserted = true;
            break;
        }
    }
    
    // If we didn't update an existing term, insert in order
    if (!termInserted) {
        // Find the right position to insert (descending order by exponent)
        int index = 0;
        bool positionFound = false;
        
        for (it = this->terms->begin(); it != this->terms->end(); it++) {
            if ((*it).exp < term.exp) {
                positionFound = true;
                break;
            }
            index++;
        }
        
        if (positionFound) {
            this->terms->add(index, term);
        } else {
            // Add at the end if no suitable position found
            this->terms->add(term);
        }
    }
}

void Polynomial::insertTerm(double coeff, int exp) {
    // Create a Term object and use the existing method
    Term newTerm(coeff, exp);
    insertTerm(newTerm);
}