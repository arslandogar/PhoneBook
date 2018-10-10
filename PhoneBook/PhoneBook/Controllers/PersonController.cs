using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using PhoneBook.Models;
using Microsoft.AspNet.Identity;
namespace PhoneBook.Controllers
{
    public class PersonController : Controller
    {
        PhoneBookDbEntities ph = new PhoneBookDbEntities();
        // GET: Person
        public ActionResult Index()
        {
            return View(ph.People.ToList());
        }

        // GET: Person/Details/5
        public ActionResult Details(int id)
        {
            var person = ph.People.Single(c => c.PersonId == id);
            return View(person);
        }

        // GET: Person/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Person/Create]\
        [HttpPost]
        public ActionResult Create(Person p)
        {
            try
            {
                // TODO: Add insert logic here

                p.AddedBy = User.Identity.GetUserId();
                p.UpdateOn = DateTime.Today.Date;
                ph.People.Add(p);
                ph.SaveChanges();
                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: Person/Edit/5
        public ActionResult Edit(int id)
        {
            var person = ph.People.Single(c => c.PersonId == id);
            return View(person);
        }

        // POST: Person/Edit/5
        [HttpPost]
        public ActionResult Edit(int id, Person p)
        {
            try
            {
                // TODO: Add update logic here
                var u_person = ph.People.Single(c => c.PersonId == id);
                TryUpdateModel(u_person);
                u_person.UpdateOn = DateTime.Today.Date;
                ph.SaveChanges();
                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: Person/Delete/5
        public ActionResult Delete(int id)
        {
            var con = ph.People.Single(c => c.PersonId == id);

            return View(con);
        }

        // POST: Person/Delete/5
        [HttpPost]
        public ActionResult Delete(int id, Person p)
        {
            try
            {
                // TODO: Add delete logic here
                var toDelete = ph.People.Single(c => c.PersonId == id);
                ph.People.Remove(toDelete);
               
                ph.SaveChanges();
                return RedirectToAction("Index");
            }
            catch
            {
                return View(p);
            }
        }

        // GET: Person/Create
        public ActionResult CreateContact()
        {
            return View();
        }

        // POST: Person/Create]\
        [HttpPost]
        public ActionResult CreateContact(int id, Contact c)
        {
            try
            {
                // TODO: Add insert logic here

                var p = ph.People.Single(co => co.PersonId == id);
                c.PersonId = id;
                p.Contacts.Add(c);
                ph.SaveChanges();
                return RedirectToAction("Index");
            }
            catch
            {
                return View();
            }
        }

        // GET: Person/Details/5
        public ActionResult ViewContacts(int id)
        {
            var person = ph.People.Single(c => c.PersonId == id);
            return View(person.Contacts);
        }
    }
}
