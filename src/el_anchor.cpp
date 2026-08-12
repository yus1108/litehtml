// Modified by yus1108
// Original file: litehtml/src/el_anchor.cpp
// Changes:
// - Modified adding pseudo-class in el_anchor::apply_stylesheet() to avoid duplicate pseudo-class addition.

#include "el_anchor.h"
#include "document.h"
#include "document_container.h"

litehtml::el_anchor::el_anchor(const std::shared_ptr<litehtml::document>& doc) : html_tag(doc)
{
}

void litehtml::el_anchor::on_click()
{
	const char* href = get_attr("href");

	if(href)
	{
		get_document()->container()->on_anchor_click(href, shared_from_this());
	}
}

void litehtml::el_anchor::apply_stylesheet( const litehtml::css& stylesheet )
{
	if( get_attr("href") )
	{
		set_pseudo_class(_link_, true);
	}
	html_tag::apply_stylesheet(stylesheet);
}
