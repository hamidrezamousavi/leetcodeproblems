ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resualt_head;
	int yekan;
	int dahgan = 0;
	ListNode* resualt = new ListNode;
	resualt_head = resualt;
	
	while(l1!=nullptr || l2!= nullptr){
		if(l1!=nullptr && l2!= nullptr){
			yekan = (l1->val+l2->val+dahgan)%10;
			dahgan = ((l1->val+l2->val+dahgan)>=10)?1:0;
			resualt_head->val = yekan;
			if((l1->next!= nullptr)||(l2->next!=nullptr)){
				resualt_head->next = new ListNode;
				resualt_head = resualt_head->next;
			}	
			l1 = l1->next;
			l2 = l2->next;
			
		}else if(l1!=nullptr && l2== nullptr){
			yekan = (l1->val+dahgan)%10;
			dahgan = ((l1->val+dahgan)>=10)?1:0;
			resualt_head->val = yekan;
			
			if((l1->next!= nullptr)){
				resualt_head->next = new ListNode;
				resualt_head = resualt_head->next;
			}
			l1 = l1->next;
			
			
			
		}else if (l1==nullptr && l2!= nullptr){
			
			yekan = (l2->val+dahgan)%10;
			dahgan = ((l2->val+dahgan)>=10)?1:0;
			resualt_head->val = yekan;
			if((l2->next!= nullptr)){
				resualt_head->next = new ListNode;
				resualt_head = resualt_head->next;
			}
			l2 = l2->next;
			
		}
		
		
	}
	if(dahgan==1){
		resualt_head->next = new ListNode;
		resualt_head = resualt_head->next;
		resualt_head->val =1;
	}
	
    return resualt;   
        
    }