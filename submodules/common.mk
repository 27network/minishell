# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    common.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 07:14:16 by kiroussa          #+#    #+#              #
#    Updated: 2024/02/17 04:27:28 by kiroussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#idiot proof
ifndef NAME
	_ = $(error NAME is not set)
endif
ifndef SRC
	_ = $(error SRC is not set)
endif
ifndef MODULE_CACHE
	_ = $(error MODULE_CACHE is not set)
endif
ifndef CACHE_DIR
	_ = $(error CACHE_DIR is not set)
endif
ifndef SRC_DIR
	_ = $(error SRC_DIR is not set)
endif
ifndef OBJ_DIR
	_ = $(error OBJ_DIR is not set)
endif
ifndef D_DIR
	_ = $(error D_DIR is not set)
endif

SRC				:=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ				:=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
D_FILES			:=	$(SRC:$(SRC_DIR)/%.c=$(D_DIR)/%.d)

DISABLE_CLEAN	:=	0

all: $(OUTPUT)

#-include $(D_FILES)

#$(D_FILES): $(D_DIR)/%.d: $(SRC_DIR)/%.c
#	@mkdir -p $(dir $@)
#	@printf "$(SPACING)Generating dependencies for $<\n"
#	@printf "$(SPACING)"
#	$(CC) $(CFLAGS) -MM $< -MT $(OBJ_DIR)/$*.o -MF $@

$(OUTPUT): $(DEPS) $(OBJ)
	@printf "$(SPACING)"
ifneq ($(IS_EXEC),1)
	@printf "💼 Linking $(OUTPUT)\n"
	@$(LD) $(LDFLAGS) $(OUTPUT) $(OBJ) 
else
	@printf "🖥️  Linking $(OUTPUT)\n"
	@$(LD) $(OBJ) -o $(OUTPUT) $(LDFLAGS)  
endif

$(DEPS):
	@printf "$(SPACING)📑 Making '$@'\n"
	@make -C ../$@ all CACHE_DIR="$(CACHE_DIR)" DEPTH="$(shell expr $(DEPTH) + 1)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(SPACING)🔨 $<\n"
	@$(CC) $(CFLAGS) -c $< -o $@

clean_deps:
	@if [ "$(DISABLE_CLEAN)" = "0" ]; then \
		printf "$(SPACING)Cleaning dependencies\n"; \
		for dep in $(DEPS); do \
			make -C "../$$dep" clean CACHE_DIR="$(CACHE_DIR)" DEPTH="$(shell expr $(DEPTH) + 1)"; \
		done; \
	fi

clean: clean_deps
	@printf "$(SPACING)"
	rm -rf $(MODULE_CACHE)
	
fclean_deps:
	@printf "$(SPACING)(F)Cleaning dependencies\n"
	@for dep in $(DEPS); do \
		make -C "../$$dep" fclean CACHE_DIR="$(CACHE_DIR)" DEPTH="$(shell expr $(DEPTH) + 1)"; \
	done

__disable_clean:
	$(eval DISABLE_CLEAN := 1)

fclean: __disable_clean fclean_deps clean
	@printf "$(SPACING)\033[31m$(OUTPUT) cleaned\033[0m\n"
	@printf "$(SPACING)"
	rm -f $(OUTPUT)

re: fclean all

print_%:
	@echo "$($*)"

.PHONY: all clean fclean re print_% clean_deps fclean_deps __disable_clean
