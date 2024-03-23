/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autogen <oss@xtrm.me>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:58:04 by kiroussa          #+#    #+#             */
/*   Updated: 2024/03/23 03:28:50 by autogen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file features.h
 * @brief This file is auto-generated. Do not edit it manually.
 * @date 2024/03/23 03:28:50
 * @see features.h.gen.sh
 */

#ifndef FEATURES_H
# define FEATURES_H
# undef FEATURES_H
# ifndef __MSH_FEATURES_H__
#  define __MSH_FEATURES_H__

/* --- BONUS_MSH --- */
#  define FEAT_PARSER_WILDCARD 1
#  define FEAT_TOK_OR 1
#  define FEAT_TOK_AND 1
#  define FEAT_TOK_PARAN 1

/* --- MANDATORY_42SH --- */
#  define FEAT_TOK_SEMICOLON 1
#  define FEAT_BUILTIN_ECHO_OPT 1
#  define FEAT_BUILTIN_CD_OPT 1
#  define FEAT_BUILTIN_TYPE 1
#  define FEAT_BUILTIN_SET 1
#  define FEAT_BUILTIN_UNSET 1
#  define FEAT_PARSER_INLINE_ASSIGN 1
#  define FEAT_PARSER_PARAM_EXPANSION 1
#  define FEAT_JOB_CONTROL 1
#  define FEAT_SIG_ALL 1
#  define FEAT_BUILTIN_ENV_DISABLE 1

/* --- MODULAR_42SH --- */
#  define FEAT_PARSER_INHIBITORS 1

/* --- BONUS_42SH (disabled) --- */

/* --- EXTRAS (disabled) --- */
#  define FEAT_BUILTIN_HELP 0
#  define FEAT_BUILTIN_HELP_SET 0

# endif // __MSH_FEATURES_H__
#endif // FEATURES_H
